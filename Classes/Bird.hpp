//
//  Bird.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#ifndef Bird_hpp
#define Bird_hpp

#include "core.h"
#include "GameObject.hpp"

USING_NS_CORE;

class CBird : public GameObject
{
public:
    CBird();
    virtual ~CBird();
    
public: // IGameObject
    virtual void initComponent()                            override;
    virtual void initStateMachine()                         override;
    virtual void initCommander()                            override;
    virtual void actionCommand(const cocos2d::Value& value) override;
    
};

#endif /* Bird_hpp */
