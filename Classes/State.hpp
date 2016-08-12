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

NS_CORE_BEGIN

class IGameObject;
class State : public cocos2d::Ref
{
public:
    State(IGameObject* pOwner);
    virtual ~State();
    
    void onEnter();
    void onUpdate(float delta);
    void onExit();
    
protected:
    IGameObject* m_pOwner;
    
    CC_SYNTHESIZE_READONLY(bool, m_bFinished, Finished);
};

NS_CORE_END

#endif /* State_hpp */
