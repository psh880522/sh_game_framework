//
//  GameObject.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 10..
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "Macro.hpp"

#include "cocos2d.h"
#include "IGameObject.hpp"

NS_CORE_BEGIN

class Commander;
class StateMachine;
class GameObject
: public cocos2d::Node
, public IGameObject
{
public:
    GameObject();
    virtual ~GameObject();
    
    virtual void initialize();
    
public: // Node
    virtual void update(float delta) override;
    
public: // IGameObject
    virtual void initComponent()                            override;
    virtual void initStateMachine()                         override;
    virtual void initCommander()                            override;
    virtual void actionCommand(const cocos2d::Value& value) override;
    
protected:   
    Commander*      m_pCommander;
    StateMachine*   m_pStateMachine;
    
};

NS_CORE_END

#endif /* GameObject_hpp */
