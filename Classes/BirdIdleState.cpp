//
//  BirdIdleState.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 16..
//
//

#include "BirdIdleState.hpp"
#include "AniRenderComponent.hpp"
#include "GameObject.hpp"

USING_NS_CORE;
USING_NS_CC;

CBirdIdleState *CBirdIdleState::create(IGameObject* pOwner)
{
    CBirdIdleState *ret = new (std::nothrow) CBirdIdleState(pOwner);
    if (ret)
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

CBirdIdleState::CBirdIdleState(IGameObject* pOwner)
: CState(pOwner)
{
}

CBirdIdleState::~CBirdIdleState()
{
}

void CBirdIdleState::onEnter()
{
    CState::onEnter();
    
    CGameObject* pOwner = dynamic_cast<CGameObject*>(getOwner());
    
    CAniRenderComponent* pCom = dynamic_cast<CAniRenderComponent*>(pOwner->getComponent("body"));
    if(pCom != nullptr)
    {
        pCom->setAnimation("breath_001", true);
    }
}

void CBirdIdleState::onUpdate(float delta)
{
    CState::onUpdate(delta);
}

void CBirdIdleState::onExit()
{
    CState::onExit();
}