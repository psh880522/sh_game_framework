//
//  CBirdMoveState.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 25..
//
//

#ifndef CBirdMoveState_hpp
#define CBirdMoveState_hpp

#include "core.h"
#include "State.hpp"

class CBirdMoveState : public core::CState
{
public:
    static CBirdMoveState* create(core::IGameObject* pOwner);
    
    CBirdMoveState(core::IGameObject* pOwner);
    virtual ~CBirdMoveState();
    
    virtual void onEnter();
    virtual void onUpdate(float delta);
    virtual void onExit();
};

#endif /* CBirdMoveState_hpp */
