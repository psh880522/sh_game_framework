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

class CCommander;
class CStateMachine;
class CGameScene
: public cocos2d::Scene
, public IGameObject
{
public:
    CGameScene();
    virtual ~CGameScene();
    
public: // Node
    virtual bool init() override;
    virtual void update(float delta) override;
    
public: // IGameScene
    virtual void initComponent()                            override;
    virtual void initStateMachine()                         override;
    virtual void initCommander()                            override;
    virtual void actionCommand(const cocos2d::Value& value) override;
    
protected:
    CCommander*      m_pCommander;
    CStateMachine*   m_pStateMachine;
    
};

NS_CORE_END

#endif /* GameScene_hpp */
