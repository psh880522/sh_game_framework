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

Commander::Commander(IGameObject* pOwner)
: m_pOwner(pOwner)
{
    
}

Commander::~Commander()
{
    
}

void Commander::initialize()
{
}

void Commander::update(float delta)
{
}

void Commander::actionCommand(const cocos2d::Value &value)
{
    CC_ASSERT(m_pOwner != nullptr);
    
    m_pOwner->actionCommand(value);
}

NS_CORE_END