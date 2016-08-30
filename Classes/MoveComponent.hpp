//
//  CMoveComponent.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 25..
//
//

#ifndef CMoveComponent_hpp
#define CMoveComponent_hpp

#include "Core.h"
#include <spine/SkeletonAnimation.h>

class CMoveComponent : public cocos2d::Component
{
public:
    static CMoveComponent* create(const std::string& strName);
    
    CMoveComponent(const std::string& strName);
    virtual ~CMoveComponent();
    
    void moveTo(const cocos2d::Vec2& dest, const std::function<void()>& onComplete);

};

#endif /* CMoveComponent_hpp */
