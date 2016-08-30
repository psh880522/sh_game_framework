//
//  CMainScene.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 16..
//
//

#include "MainScene.hpp"
#include "Bird.hpp"

USING_NS_CC;
USING_NS_CORE;

CMainScene *CMainScene::create()
{
    CMainScene *ret = new (std::nothrow) CMainScene();
    if (ret && ret->init())
    {
        ret->initialize();
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

CMainScene::CMainScene()
{
    
}

CMainScene::~CMainScene()
{
    
}

void CMainScene::initialize()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    for(int i = 0; i < 10; ++i)
    {
        std::string str = StringUtils::format("bird%02d", i + 1);
        CBird* pBird = CBird::create(str);
        pBird->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
        pBird->setPosition(Vec2(visibleSize * 0.5f));
        addChild(pBird);
    }
}

void CMainScene::initComponent()
{
    
}

void CMainScene::initStateMachine()
{
}

void CMainScene::initCommander()
{
}

void CMainScene::actionCommand(const cocos2d::Value &value)
{
}