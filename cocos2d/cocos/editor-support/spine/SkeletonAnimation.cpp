/******************************************************************************
 * Spine Runtimes Software License
 * Version 2.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * You are granted a perpetual, non-exclusive, non-sublicensable and
 * non-transferable license to install, execute and perform the Spine Runtimes
 * Software (the "Software") solely for internal use. Without the written
 * permission of Esoteric Software (typically granted by licensing Spine), you
 * may not (a) modify, translate, adapt or otherwise create derivative works,
 * improvements of the Software or develop new applications using the Software
 * or (b) remove, delete, alter or obscure any trademarks or any copyright,
 * trademark, patent or other intellectual property or proprietary rights
 * notices on or in the Software, including any copy thereof. Redistributions
 * in binary or source form must include this license and terms.
 * 
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include <spine/SkeletonAnimation.h>
#include <spine/spine-cocos2dx.h>
#include <spine/extension.h>
#include <algorithm>

USING_NS_CC;
using std::min;
using std::max;
using std::vector;

namespace spine {
SkeletonAnimation::TYPE_SKELETON_DATA_CACHE SkeletonAnimation::s_skeleton_data_cache;
void animationCallback (spAnimationState* state, int trackIndex, spEventType type, spEvent* event, int loopCount) {
	((SkeletonAnimation*)state->rendererObject)->onAnimationStateEvent(trackIndex, type, event, loopCount);
}

void trackEntryCallback (spAnimationState* state, int trackIndex, spEventType type, spEvent* event, int loopCount) {
	((SkeletonAnimation*)state->rendererObject)->onTrackEntryEvent(trackIndex, type, event, loopCount);
}

typedef struct _TrackEntryListeners {
	StartListener startListener;
	EndListener endListener;
	CompleteListener completeListener;
	EventListener eventListener;
} _TrackEntryListeners;

static _TrackEntryListeners* getListeners (spTrackEntry* entry) {
	if (!entry->rendererObject) {
		entry->rendererObject = NEW(spine::_TrackEntryListeners);
		entry->listener = trackEntryCallback;
	}
	return (_TrackEntryListeners*)entry->rendererObject;
}

void disposeTrackEntry (spTrackEntry* entry) {
	if (entry->rendererObject) FREE(entry->rendererObject);
	_spTrackEntry_dispose(entry);
}

//

SkeletonAnimation* SkeletonAnimation::createWithData (spSkeletonData* skeletonData) {
	SkeletonAnimation* node = new SkeletonAnimation(skeletonData);
	node->autorelease();
	return node;
}

SkeletonAnimation* SkeletonAnimation::createWithFile (const std::string& skeletonDataFile, spAtlas* atlas, float scale) {
	SkeletonAnimation* node = new SkeletonAnimation(skeletonDataFile, atlas, scale);
	node->autorelease();
	return node;
}

SkeletonAnimation* SkeletonAnimation::createWithFile (const std::string& skeletonDataFile, const std::string& atlasFile, float scale) {
    
//	SkeletonAnimation* node = new SkeletonAnimation(skeletonDataFile, atlasFile, scale);
//	node->autorelease();
//	return node;
    
    spSkeletonData* skeletonData;
    auto cache_iter = spine::SkeletonAnimation::s_skeleton_data_cache.find(skeletonDataFile);
    if (cache_iter != spine::SkeletonAnimation::s_skeleton_data_cache.end())
    {
        skeletonData = cache_iter->second;
    }
    else
    {
        spAtlas* atlas = spAtlas_createFromFile(atlasFile.c_str(), 0);
        CCASSERT(atlas, "Error reading atlas file.");
        
        spSkeletonJson* json = spSkeletonJson_create(atlas);
        json->scale = scale;
        skeletonData = spSkeletonJson_readSkeletonDataFile(json, skeletonDataFile.c_str());
        CCASSERT(skeletonData, json->error ? json->error : "Error reading skeleton data file.");
        spSkeletonJson_dispose(json);
        
        spine::SkeletonAnimation::s_skeleton_data_cache.insert(TYPE_SKELETON_DATA_CACHE::value_type(skeletonDataFile, skeletonData));
        CCLOG("SkeletonAnimation add cache : %s", skeletonDataFile.c_str());
    }
    
    SkeletonAnimation* node = new (std::nothrow) SkeletonAnimation(skeletonData);
    node->autorelease();
    return node;
}
    
SkeletonAnimation* SkeletonAnimation::createWithFile (const std::string& skeletonDataFile, const std::string& atlasFile,  cocos2d::Texture2D* texture, cocos2d::Vec2 vAddPos, float scale, bool bAutoRelease)
{
    SkeletonAnimation* node = new SkeletonAnimation(skeletonDataFile, atlasFile, texture, vAddPos, scale);
    if( bAutoRelease ) node->autorelease();
    return node;
}

void SkeletonAnimation::initialize () {
	_ownsAnimationStateData = true;
	_state = spAnimationState_create(spAnimationStateData_create(_skeleton->data));
	_state->rendererObject = this;
	_state->listener = animationCallback;

	_spAnimationState* stateInternal = (_spAnimationState*)_state;
	stateInternal->disposeTrackEntry = disposeTrackEntry;
}

SkeletonAnimation::SkeletonAnimation ()
		: SkeletonRenderer() {
}

SkeletonAnimation::SkeletonAnimation (spSkeletonData *skeletonData)
		: SkeletonRenderer(skeletonData) {
	initialize();
}

SkeletonAnimation::SkeletonAnimation (const std::string& skeletonDataFile, spAtlas* atlas, float scale)
		: SkeletonRenderer(skeletonDataFile, atlas, scale) {
	initialize();
}

SkeletonAnimation::SkeletonAnimation (const std::string& skeletonDataFile, const std::string& atlasFile, float scale)
		: SkeletonRenderer(skeletonDataFile, atlasFile, scale) {
	initialize();
}
    
SkeletonAnimation::SkeletonAnimation (const std::string& skeletonDataFile, const std::string& atlasFile, cocos2d::Texture2D* texture, cocos2d::Vec2 vAddPos, float scale)
    : SkeletonRenderer(skeletonDataFile, atlasFile, texture, vAddPos, scale)
{
    initialize();
}

SkeletonAnimation::~SkeletonAnimation () {
	if (_ownsAnimationStateData) spAnimationStateData_dispose(_state->data);
	spAnimationState_dispose(_state);
}

void SkeletonAnimation::update (float deltaTime) {
	super::update(deltaTime);

	deltaTime *= _timeScale;
	spAnimationState_update(_state, deltaTime);
	spAnimationState_apply(_state, _skeleton);
	spSkeleton_updateWorldTransform(_skeleton);
}

void SkeletonAnimation::setAnimationStateData (spAnimationStateData* stateData) {
	CCASSERT(stateData, "stateData cannot be null.");

	if (_ownsAnimationStateData) spAnimationStateData_dispose(_state->data);
	spAnimationState_dispose(_state);

	_ownsAnimationStateData = false;
	_state = spAnimationState_create(stateData);
	_state->rendererObject = this;
	_state->listener = animationCallback;
}

void SkeletonAnimation::setMix (const std::string& fromAnimation, const std::string& toAnimation, float duration) {
	spAnimationStateData_setMixByName(_state->data, fromAnimation.c_str(), toAnimation.c_str(), duration);
}

spTrackEntry* SkeletonAnimation::setAnimation (int trackIndex, const std::string& name, bool loop) {
	spAnimation* animation = spSkeletonData_findAnimation(_skeleton->data, name.c_str());
	if (!animation) {
		log("Spine: Animation not found: %s", name.c_str());
		return 0;
	}
	return spAnimationState_setAnimation(_state, trackIndex, animation, loop);
}

spTrackEntry* SkeletonAnimation::addAnimation (int trackIndex, const std::string& name, bool loop, float delay) {
	spAnimation* animation = spSkeletonData_findAnimation(_skeleton->data, name.c_str());
	if (!animation) {
		log("Spine: Animation not found: %s", name.c_str());
		return 0;
	}
	return spAnimationState_addAnimation(_state, trackIndex, animation, loop, delay);
}

spTrackEntry* SkeletonAnimation::getCurrent (int trackIndex) { 
	return spAnimationState_getCurrent(_state, trackIndex);
}

void SkeletonAnimation::clearTracks () {
	spAnimationState_clearTracks(_state);
}

void SkeletonAnimation::clearTrack (int trackIndex) {
	spAnimationState_clearTrack(_state, trackIndex);
}

void SkeletonAnimation::onAnimationStateEvent (int trackIndex, spEventType type, spEvent* event, int loopCount) {
	switch (type) {
	case SP_ANIMATION_START:
		if (_startListener) _startListener(trackIndex);
		break;
	case SP_ANIMATION_END:
		if (_endListener) _endListener(trackIndex);
		break;
	case SP_ANIMATION_COMPLETE:
		if (_completeListener) _completeListener(trackIndex, loopCount);
		break;
	case SP_ANIMATION_EVENT:
		if (_eventListener) _eventListener(trackIndex, event);
		break;
	}
}

void SkeletonAnimation::onTrackEntryEvent (int trackIndex, spEventType type, spEvent* event, int loopCount) {
	spTrackEntry* entry = spAnimationState_getCurrent(_state, trackIndex);
	if (!entry->rendererObject) return;
	_TrackEntryListeners* listeners = (_TrackEntryListeners*)entry->rendererObject;
	switch (type) {
	case SP_ANIMATION_START:
		if (listeners->startListener) listeners->startListener(trackIndex);
		break;
	case SP_ANIMATION_END:
		if (listeners->endListener) listeners->endListener(trackIndex);
		break;
	case SP_ANIMATION_COMPLETE:
		if (listeners->completeListener) listeners->completeListener(trackIndex, loopCount);
		break;
	case SP_ANIMATION_EVENT:
		if (listeners->eventListener) listeners->eventListener(trackIndex, event);
		break;
	}
}

void SkeletonAnimation::setStartListener (const StartListener& listener) {
	_startListener = listener;
}

void SkeletonAnimation::setEndListener (const EndListener& listener) {
	_endListener = listener;
}

void SkeletonAnimation::setCompleteListener (const CompleteListener& listener) {
	_completeListener = listener;
}

void SkeletonAnimation::setEventListener (const EventListener& listener) {
	_eventListener = listener;
}

void SkeletonAnimation::setTrackStartListener (spTrackEntry* entry, const StartListener& listener) {
	getListeners(entry)->startListener = listener;
}

void SkeletonAnimation::setTrackEndListener (spTrackEntry* entry, const EndListener& listener) {
	getListeners(entry)->endListener = listener;
}

void SkeletonAnimation::setTrackCompleteListener (spTrackEntry* entry, const CompleteListener& listener) {
	getListeners(entry)->completeListener = listener;
}

void SkeletonAnimation::setTrackEventListener (spTrackEntry* entry, const EventListener& listener) {
	getListeners(entry)->eventListener = listener;
}

spAnimationState* SkeletonAnimation::getState() const {
	return _state;
}

void SkeletonAnimation::removeCache(const std::string& filename)
{
    auto cache_iter = s_skeleton_data_cache.find(filename);
    if (cache_iter == s_skeleton_data_cache.end()) return;
    
    spSkeletonData_dispose(cache_iter->second);
    s_skeleton_data_cache.erase(cache_iter);
}

void SkeletonAnimation::removeCacheAll()
{
    for (auto cache_iter = s_skeleton_data_cache.begin(); cache_iter != s_skeleton_data_cache.end();)
    {
        spSkeletonData_dispose(cache_iter->second);
        ++cache_iter;
    }
    
    
    s_skeleton_data_cache.clear();
}
    
}
