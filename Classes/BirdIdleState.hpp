//
//  BirdIdleState.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 16..
//
//

#ifndef BirdIdleState_hpp
#define BirdIdleState_hpp

#include "core.h"
#include "State.hpp"

class CBirdIdleState : public core::CState
{
public:
    static CBirdIdleState* create(core::IGameObject* pOwner);
    
    CBirdIdleState(core::IGameObject* pOwner);
    virtual ~CBirdIdleState();
    
    virtual void onEnter();
    virtual void onUpdate(float delta);
    virtual void onExit();
};

#endif /* BirdIdleState_hpp */
