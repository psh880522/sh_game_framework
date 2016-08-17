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

CState::CState(IGameObject* pOwner)
: m_pOwner(pOwner)
, m_bFinished(true)
{
}

CState::~CState()
{
}

void CState::onEnter()
{
    m_bFinished = false;
}

void CState::onUpdate(float delta)
{
}

void CState::onExit()
{
}

NS_CORE_END