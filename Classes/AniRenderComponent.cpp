//
//  CAniRenderComponent.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#include "AniRenderComponent.hpp"

USING_NS_CC;

CAniRenderComponent* CAniRenderComponent::create(const std::string& strName, const std::string& strFileName)
{
    CAniRenderComponent * ret = new (std::nothrow) CAniRenderComponent(strName, strFileName);
    if (ret != nullptr && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

CAniRenderComponent::CAniRenderComponent(const std::string& strName, const std::string& strFileName)
: m_pRenderer()
, m_strFileName(strFileName)
{
    setName(strName);
}

CAniRenderComponent::~CAniRenderComponent(void)
{
}

void CAniRenderComponent::setAnimation(const std::string& strAniName, const bool bLoop)
{
    m_pRenderer->setAnimation(0, strAniName, bLoop);
}

void CAniRenderComponent::addAnimation(const std::string& strAniName, bool bLoop, float fDelay)
{
    m_pRenderer->addAnimation(0, strAniName, bLoop, fDelay);
}

bool CAniRenderComponent::setSkin(const std::string& skinName)
{
    return m_pRenderer->setSkin(skinName);
}

void CAniRenderComponent::setPosition(const cocos2d::Vec2& position)
{
    m_pRenderer->setPosition(position);
}

void CAniRenderComponent::onEnter()
{
    m_pRenderer = spine::SkeletonAnimation::createWithFile(m_strFileName + ".json",
                                                           m_strFileName + ".atlas");
    getOwner()->addChild(m_pRenderer);
}

void CAniRenderComponent::onExit()
{
}

void CAniRenderComponent::update(float delta)
{
}