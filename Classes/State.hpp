//
//  State.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#ifndef State_hpp
#define State_hpp

#include "cocos2d.h"
#include "Macro.hpp"

NS_CORE_BEGIN

class State : public cocos2d::Ref
{
public:
    static State* create();
    
    State();
    virtual ~State();
    
    void onEnter();
    void onUpdate(float delta);
    void onExit();
    
    CC_SYNTHESIZE_READONLY(bool, m_bFinished, Finished);
};

NS_CORE_END

#endif /* State_hpp */
