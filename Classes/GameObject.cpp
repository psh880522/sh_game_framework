//
//  GameObject.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 10..
//
//

#include "GameObject.hpp"
#include "Commander.hpp"
#include "StateMachine.hpp"

NS_CORE_BEGIN

CGameObject::CGameObject()
: m_pCommander()
, m_pStateMachine()
{
    
}

CGameObject::~CGameObject()
{
    
}

bool CGameObject::init()
{
    initComponent();
    initStateMachine();
    initCommander();
    
    return true;
}

void CGameObject::update(float delta)
{
    Node::update(delta);
    
    if(m_pCommander != nullptr)
    {
        m_pCommander->update(delta);
    }
    
    if(m_pStateMachine != nullptr)
    {
        m_pStateMachine->update(delta);
    }
}

void CGameObject::initComponent()
{
}

void CGameObject::initStateMachine()
{
}

void CGameObject::initCommander()
{
}

void CGameObject::actionCommand(const cocos2d::Value &value)
{
}
    
NS_CORE_END
