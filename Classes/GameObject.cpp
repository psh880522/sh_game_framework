//
//  GameObject.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 10..
//
//

#include "GameObject.hpp"

NS_CORE_BEGIN

CGameObject::CGameObject()
: m_pCommander()
, m_pStateMachine()
{
    
}

CGameObject::~CGameObject()
{
    if(m_pCommander != nullptr)
    {
        m_pCommander->release();
    }
    
    if(m_pStateMachine != nullptr)
    {
        m_pStateMachine->release();
    }
}

void CGameObject::changeState(int nState, CStateMachine::ETransition eTransition)
{
    if(m_pStateMachine != nullptr)
    {
        m_pStateMachine->changeState(nState, eTransition);
    }
}

int CGameObject::getCurrentState()
{
    if(m_pStateMachine != nullptr)
    {
        return m_pStateMachine->getCurrentState();
    }
    
    return -1;
}

void CGameObject::addCommander(CCommander* pCommander)
{
    pCommander->retain();
    m_pCommander = pCommander;
}

void CGameObject::addStateMachine(CStateMachine* pStateMachine)
{
    pStateMachine->retain();
    m_pStateMachine = pStateMachine;
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
