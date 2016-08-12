//
//  StateMachine.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#include "StateMachine.hpp"

NS_CORE_BEGIN

StateMachine *StateMachine::create()
{
    StateMachine *ret = new (std::nothrow) StateMachine();
    if (ret)
    {
        ret->initialize();
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

StateMachine::StateMachine()
: m_mStates()
, m_nCurrentState(-1)
, m_nNextState(-1)
{
    
}

StateMachine::~StateMachine()
{
    m_mStates.clear();
}

void StateMachine::initialize()
{
    m_mStates.clear();
}

void StateMachine::update(float delta)
{
    CC_ASSERT(m_mStates.find(m_nCurrentState) != m_mStates.end());
    
    State* pCurrentState = m_mStates.at(m_nCurrentState);
    pCurrentState->onUpdate(delta);
    
    if(pCurrentState->getFinished() == true && m_nNextState > -1)
    {
        pCurrentState->onExit();
        
        _changeNextState();
    }
}

void StateMachine::addState(int nState, State* pState)
{
    CC_ASSERT(m_mStates.find(nState) == m_mStates.end());
    
    m_mStates.insert(nState, pState);
}

void StateMachine::changeState(int nState, ETransition eTransition)
{
    CC_ASSERT(m_mStates.find(nState) != m_mStates.end());
    
    switch (eTransition) {
        case ETransition::TR_SAFE:
        {
            m_nNextState = nState;
        }break;
        case ETransition::TR_OVERRIDE:
        {
            m_nNextState = nState;
            
            State* pCurrentState = m_mStates.at(m_nCurrentState);
            pCurrentState->onExit();
            
            _changeNextState();
        }break;
        default: break;
    }
}

void StateMachine::_changeNextState()
{
    CC_ASSERT(m_mStates.find(m_nNextState) != m_mStates.end());
    
    m_nCurrentState = m_nNextState;
    m_nNextState = -1;
    
    State* pCurrentState = m_mStates.at(m_nCurrentState);
    pCurrentState->onEnter();
}

NS_CORE_END