//
//  StateMachine.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#include "StateMachine.hpp"
#include "State.hpp"

NS_CORE_BEGIN

CStateMachine *CStateMachine::create()
{
    CStateMachine *ret = new (std::nothrow) CStateMachine();
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

CStateMachine::CStateMachine()
: m_mStates()
, m_nCurrentState(-1)
, m_nNextState(-1)
{
    
}

CStateMachine::~CStateMachine()
{
    m_mStates.clear();
}

void CStateMachine::initialize()
{
    m_mStates.clear();
}

void CStateMachine::update(float delta)
{
    CC_ASSERT(m_mStates.find(m_nCurrentState) != m_mStates.end());
    
    CState* pCurrentState = m_mStates.at(m_nCurrentState);
    pCurrentState->onUpdate(delta);
    
    if(pCurrentState->getFinished() == true && m_nNextState > -1)
    {
        pCurrentState->onExit();
        
        _changeNextState();
    }
}

void CStateMachine::addState(int nState, CState* pState)
{
    CC_ASSERT(m_mStates.find(nState) == m_mStates.end());
    
    m_mStates.insert(nState, pState);
}

void CStateMachine::changeState(int nState, ETransition eTransition)
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
            
            CState* pCurrentState = m_mStates.at(m_nCurrentState);
            pCurrentState->onExit();
            
            _changeNextState();
        }break;
        default: break;
    }
}

void CStateMachine::_changeNextState()
{
    CC_ASSERT(m_mStates.find(m_nNextState) != m_mStates.end());
    
    m_nCurrentState = m_nNextState;
    m_nNextState = -1;
    
    CState* pCurrentState = m_mStates.at(m_nCurrentState);
    pCurrentState->onEnter();
}

NS_CORE_END