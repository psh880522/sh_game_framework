//
//  StateMachine.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include "core.h"

NS_CORE_BEGIN

class CState;
class CStateMachine : public cocos2d::Ref
{
public:
    enum class ETransition
    {
        TR_SAFE,
        TR_OVERRIDE,
        TR_NUM
    };
public:
    static CStateMachine* create();
    
    CStateMachine();
    virtual ~CStateMachine();
    
    void initialize();
    
    void update(float delta);
    
    void addState(int nState, CState* pState);
    
    void changeState(int nState, ETransition eTransition = ETransition::TR_SAFE);
    
private:
    void _changeNextState();

private:
    cocos2d::Map<int, CState*> m_mStates;
    
    CC_SYNTHESIZE_READONLY(int, m_nCurrentState, CurrentState);
    CC_SYNTHESIZE(int, m_nNextState,    NextState);
};

NS_CORE_END

#endif /* StateMachine_hpp */
