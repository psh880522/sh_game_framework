//
//  CMoveComponent.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 25..
//
//

#include "MoveComponent.hpp"

USING_NS_CC;

CMoveComponent* CMoveComponent::create(const std::string& strName)
{
    CMoveComponent * ret = new (std::nothrow) CMoveComponent(strName);
    if (ret != nullptr && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

CMoveComponent::CMoveComponent(const std::string& strName)
{
    setName(strName);
}

CMoveComponent::~CMoveComponent(void)
{
}

void CMoveComponent::moveTo(const Vec2& dest, const std::function<void()>& onComplete)
{
    getOwner()->stopAllActions();
    
//    MoveTo* pMoveTo = MoveTo::create(1.0f, dest);
//    CallFunc* pCall = CallFunc::create([onComplete](){
//        if(onComplete)
//        {
//            onComplete();
//        }
//    });
//    
//    
//    getOwner()->runAction(Sequence::create(EaseInOut::create(pMoveTo, 0.9f), pCall, nullptr));
    
    Vec2 vStartPos = Vec2(getOwner()->getPosition().x, getOwner()->getPosition().y - 150);
    
    float fLandDis = std::min(100.0f, std::abs(vStartPos.y - dest.y) / 2);
    Vec2 vLandPos = Vec2(dest.x, dest.y + fLandDis);
    
    ccBezierConfig config;
    config.controlPoint_1 = Vec2(vStartPos.x, vStartPos.y - 80);
    config.controlPoint_2 = Vec2(vLandPos.x, vLandPos.y + 80);
    config.endPosition = vLandPos;
    
    MoveTo*     pFall   = MoveTo::create(0.5f, vStartPos);
    BezierTo*   pFly    = BezierTo::create(0.9f, config);
    MoveTo*     pLand   = MoveTo::create(0.5f, dest);
    Sequence*   pSeq    = Sequence::create(EaseBackOut::create(pFall),
                                           EaseSineInOut::create(pFly),
                                           EaseBackIn::create(pLand),
                                           CallFunc::create([onComplete]()
                                                            {
                                                                if(onComplete)
                                                                {
                                                                    onComplete();
                                                                }
                                                            }),
                                           nullptr);
    
    getOwner()->runAction(pSeq);
}
