//
//  GameScene.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "core.h"
#include "IGameObject.hpp"

NS_CORE_BEGIN

class Commander;
class StateMachine;
class GameScene
: public cocos2d::Scene
, public IGameObject
{
public:
    GameScene();
    virtual ~GameScene();
    
    virtual void initialize();
    
public: // Node
    virtual void update(float delta) override;
    
public: // IGameScene
    virtual void initComponent()                            override;
    virtual void initStateMachine()                         override;
    virtual void initCommander()                            override;
    virtual void actionCommand(const cocos2d::Value& value) override;
    
protected:
    Commander*      m_pCommander;
    StateMachine*   m_pStateMachine;
    
};

NS_CORE_END

#endif /* GameScene_hpp */
