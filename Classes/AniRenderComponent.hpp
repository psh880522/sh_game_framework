//
//  AniRenderComponent.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#ifndef AniRenderComponent_hpp
#define AniRenderComponent_hpp

#include "Core.h"
#include <spine/SkeletonAnimation.h>

class CAniRenderComponent : public cocos2d::Component
{
public:
    static CAniRenderComponent* create(const std::string& strFileName);
    
    CAniRenderComponent();
    virtual ~CAniRenderComponent();
    
    void initialize(const std::string& strFileName);
    void setAnimation(const std::string& strAniName, const bool bLoop);
    
public: // Component
    virtual void onEnter();
    virtual void onExit();
    virtual void update(float delta);
    
private:
    spine::SkeletonAnimation* m_pRenderer;
};

#endif /* AniRenderComponent_hpp */
