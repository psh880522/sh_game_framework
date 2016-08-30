//
//  GameObject.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 10..
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "core.h"
#include "IGameObject.hpp"
#include "Commander.hpp"
#include "StateMachine.hpp"

NS_CORE_BEGIN

class CGameObject
: public cocos2d::Node
, public IGameObject
{
public:
    CGameObject();
    virtual ~CGameObject();
    
    void changeState(int nState, CStateMachine::ETransition eTransition);
    int getCurrentState();
    
protected:
    void addCommander(CCommander* pCommander);
    void addStateMachine(CStateMachine* pStateMachine);
    
public: // Node
    virtual bool init() override;
    virtual void update(float delta) override;
    
public: // IGameObject
    virtual void initComponent()                            override;
    virtual void initStateMachine()                         override;
    virtual void initCommander()                            override;
    virtual void actionCommand(const cocos2d::Value& value) override;
    
protected:   
    CCommander*      m_pCommander;
    CStateMachine*   m_pStateMachine;
    
};

NS_CORE_END

#endif /* GameObject_hpp */
