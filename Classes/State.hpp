//
//  State.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#ifndef State_hpp
#define State_hpp

#include "core.h"
#include "IGameObject.hpp"

NS_CORE_BEGIN

class CState : public cocos2d::Ref
{
public:
    CState(IGameObject* pOwner);
    virtual ~CState();
    
    virtual void onEnter();
    virtual void onUpdate(float delta);
    virtual void onExit();
    
protected:
    CC_SYNTHESIZE_READONLY(IGameObject*, m_pOwner, Owner);
    CC_SYNTHESIZE_READONLY(bool, m_bFinished, Finished);
};

NS_CORE_END

#endif /* State_hpp */
