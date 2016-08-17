//
//  CMainScene.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 16..
//
//

#ifndef CMainScene_hpp
#define CMainScene_hpp

#include "core.h"
#include "GameScene.hpp"

class CMainScene : public core::CGameScene
{
public:
    CMainScene();
    virtual ~CMainScene();
    
    static CMainScene* create();
    void initialize();
    
public: // IGameObject
    virtual void initComponent()                            override;
    virtual void initStateMachine()                         override;
    virtual void initCommander()                            override;
    virtual void actionCommand(const cocos2d::Value& value) override;
    
};

#endif /* CMainScene_hpp */
