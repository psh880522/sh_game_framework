//
//  Bird.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#include "Bird.hpp"
#include "AniRenderComponent.hpp"
#include "StateMachine.hpp"

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
    CAniRenderComponent* pCom = dynamic_cast<CAniRenderComponent*>(getComponent("body"));
    if(pCom != nullptr)
    {
        pCom->setSkin(strSkin);
        pCom->setAnimation("breath_001", true);
    }
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
}

void CBird::initStateMachine()
{
    m_pStateMachine = CStateMachine::create();
}

void CBird::initCommander()
{
}

void CBird::actionCommand(const cocos2d::Value &value)
{
}