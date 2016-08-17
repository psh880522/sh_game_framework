//
//  Commander.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#include "Commander.hpp"
#include "IGameObject.hpp"

NS_CORE_BEGIN

CCommander::CCommander(IGameObject* pOwner)
: m_pOwner(pOwner)
{
    
}

CCommander::~CCommander()
{
    
}

void CCommander::initialize()
{
}

void CCommander::update(float delta)
{
}

void CCommander::actionCommand(const cocos2d::Value &value)
{
    CC_ASSERT(m_pOwner != nullptr);
    
    m_pOwner->actionCommand(value);
}

NS_CORE_END