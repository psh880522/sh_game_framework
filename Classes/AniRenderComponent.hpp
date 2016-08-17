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
    static CAniRenderComponent* create(const std::string& strName, const std::string& strFileName);
    
    CAniRenderComponent(const std::string& strName, const std::string& strFileName);
    virtual ~CAniRenderComponent();
    
    void setAnimation(const std::string& strAniName, const bool bLoop);
    bool setSkin(const std::string& skinName);
    void setPosition(const cocos2d::Vec2& position);
    
public: // Component
    virtual void onEnter();
    virtual void onExit();
    virtual void update(float delta);
    
private:
    spine::SkeletonAnimation* m_pRenderer;
    std::string m_strFileName;
};

#endif /* AniRenderComponent_hpp */
