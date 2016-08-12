//
//  IGameObject.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#ifndef IGameObject_hpp
#define IGameObject_hpp

#include "core.h"

NS_CORE_BEGIN
    
class IGameObject
{
public:
    IGameObject(){}
    virtual ~IGameObject(){}
    
    virtual void initComponent() = 0;
    virtual void initStateMachine() = 0;
    virtual void initCommander() = 0;
    virtual void actionCommand(const cocos2d::Value& value) = 0;
    
};
    
NS_CORE_END

#endif /* IGameObject_hpp */
