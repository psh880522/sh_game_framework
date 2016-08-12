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

GameScene::GameScene()
: m_pCommander()
, m_pStateMachine()
{
    
}

GameScene::~GameScene()
{
    
}

void GameScene::initialize()
{
    initComponent();
    initStateMachine();
    initCommander();
}

void GameScene::update(float delta)
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

void GameScene::initComponent()
{
}

void GameScene::initStateMachine()
{
}

void GameScene::initCommander()
{
}

void GameScene::actionCommand(const cocos2d::Value &value)
{
}

NS_CORE_END