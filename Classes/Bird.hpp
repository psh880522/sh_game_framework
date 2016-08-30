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

class CBird : public core::CGameObject
{
public:
    enum ECommand
    {
        CMD_MOVE,
    };
    
    enum EState
    {
        ST_IDLE,
        ST_MOVE,
    };
    
public:
    CBird();
    virtual ~CBird();
    
    static CBird* create(const std::string& strSkin);
    void initialize(const std::string& strSkin);

public:
    virtual void setContentSize(const cocos2d::Size& size) override;
    
public: // IGameObject
    virtual void initComponent()                            override;
    virtual void initStateMachine()                         override;
    virtual void initCommander()                            override;
    virtual void actionCommand(const cocos2d::Value& value) override;
    
};

#endif /* Bird_hpp */
