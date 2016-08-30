//
//  Bird.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#include "Bird.hpp"
#include "AniRenderComponent.hpp"
#include "MoveComponent.hpp"

#include "BirdIdleState.hpp"
#include "BirdMoveState.hpp"

#include "BirdCommander.hpp"

USING_NS_CORE;
USING_NS_CC;

CBird *CBird::create(const std::string& strSkin)
{
    CBird *ret = new (std::nothrow) CBird();
    if (ret && ret->init())
    {
        ret->initialize(strSkin);
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

CBird::CBird()
{
}

CBird::~CBird()
{
}

void CBird::initialize(const std::string& strSkin)
{
    setContentSize(Size(100, 100));
    
    CAniRenderComponent* pCom = dynamic_cast<CAniRenderComponent*>(getComponent("body"));
    if(pCom != nullptr)
    {
        pCom->setSkin(strSkin);
    }
    
    m_pStateMachine->changeState(ST_IDLE, CStateMachine::TR_OVERRIDE);
    
    scheduleUpdate();
}

void CBird::setContentSize(const cocos2d::Size& size)
{
    CGameObject::setContentSize(size);
    
    CAniRenderComponent* pCom = dynamic_cast<CAniRenderComponent*>(getComponent("body"));
    if(pCom != nullptr)
    {
        pCom->setPosition(Vec2(size.width * 0.5f, 0));
    }
}

void CBird::initComponent()
{
    addComponent(CAniRenderComponent::create("body", "bird"));
    addComponent(CMoveComponent::create("move"));
}

void CBird::initStateMachine()
{
    addStateMachine(CStateMachine::create());
    m_pStateMachine->addState(ST_IDLE, CBirdIdleState::create(this));
    m_pStateMachine->addState(ST_MOVE, CBirdMoveState::create(this));
}

void CBird::initCommander()
{
    addCommander(CBirdCommander::create(this));
}

void CBird::actionCommand(const cocos2d::Value &value)
{
    switch (value.asInt()) {
        case CMD_MOVE:
        {
            changeState(ST_MOVE, CStateMachine::TR_OVERRIDE);
        }break;
        default:
            break;
    }
}