//
//  CBirdMoveState.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 25..
//
//

#include "BirdMoveState.hpp"
#include "AniRenderComponent.hpp"
#include "MoveComponent.hpp"
#include "Bird.hpp"

USING_NS_CORE;
USING_NS_CC;

CBirdMoveState *CBirdMoveState::create(IGameObject* pOwner)
{
    CBirdMoveState *ret = new (std::nothrow) CBirdMoveState(pOwner);
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

CBirdMoveState::CBirdMoveState(IGameObject* pOwner)
: CState(pOwner)
{
}

CBirdMoveState::~CBirdMoveState()
{
}

void CBirdMoveState::onEnter()
{
    CState::onEnter();
    
    CGameObject* pOwner = dynamic_cast<CGameObject*>(getOwner());
    
    CAniRenderComponent* pBody = dynamic_cast<CAniRenderComponent*>(pOwner->getComponent("body"));
    if(pBody != nullptr)
    {
        pBody->setAnimation("pickMove_001", true);
    }
    
    CMoveComponent* pMove = dynamic_cast<CMoveComponent*>(pOwner->getComponent("move"));
    if(pMove != nullptr)
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 destPos = Vec2(random(pOwner->getContentSize().width * 0.5f,
                                   visibleSize.width - pOwner->getContentSize().width * 0.5f),
                            random(0.0f,
                                   visibleSize.height - pOwner->getContentSize().height));
        
        pMove->moveTo(destPos, [this]()
        {
            m_bFinished = true;
        });
    }
    
    pOwner->changeState(CBird::ST_IDLE, CStateMachine::TR_SAFE);
}

void CBirdMoveState::onUpdate(float delta)
{
    CState::onUpdate(delta);
}

void CBirdMoveState::onExit()
{
    CState::onExit();
}