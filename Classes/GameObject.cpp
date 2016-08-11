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

GameObject::GameObject()
: m_pCommander()
, m_pStateMachine()
{
    
}

GameObject::~GameObject()
{
    
}

void GameObject::initialize()
{
    initComponent();
    initStateMachine();
    initCommander();
    
    scheduleUpdate();
}

void GameObject::update(float delta)
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

void GameObject::initComponent()
{
}

void GameObject::initStateMachine()
{
}

void GameObject::initCommander()
{
}

void GameObject::actionCommand(const cocos2d::Value &value)
{
}
    
NS_CORE_END