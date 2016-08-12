//
//  State.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#include "State.hpp"
#include "IGameObject.hpp"

NS_CORE_BEGIN

State::State(IGameObject* pOwner)
: m_pOwner(pOwner)
, m_bFinished(true)
{
}

State::~State()
{
}

void State::onEnter()
{
    m_bFinished = false;
}

void State::onUpdate(float delta)
{
}

void State::onExit()
{
}

NS_CORE_END