//
//  GameScene.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#include "GameScene.hpp"
#include "Commander.hpp"
#include "StateMachine.hpp"

NS_CORE_BEGIN

CGameScene::CGameScene()
: m_pCommander()
, m_pStateMachine()
{
    
}

CGameScene::~CGameScene()
{
    
}

bool CGameScene::init()
{
    initComponent();
    initStateMachine();
    initCommander();
    
    return true;
}

void CGameScene::update(float delta)
{
    Node::update(delta);
    
    if(m_pCommander != nullptr)
    {
        m_pCommander->update(delta);
    }
    
    if(m_pStateMachine != nullptr)
    {
        m_pStateMachine->update(delta);
    }
}

void CGameScene::initComponent()
{
}

void CGameScene::initStateMachine()
{
}

void CGameScene::initCommander()
{
}

void CGameScene::actionCommand(const cocos2d::Value &value)
{
}

NS_CORE_END