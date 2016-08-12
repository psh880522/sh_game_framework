//
//  CAniRenderComponent.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 12..
//
//

#include "AniRenderComponent.hpp"

CAniRenderComponent* CAniRenderComponent::create(const std::string& strFileName)
{
    CAniRenderComponent * ret = new (std::nothrow) CAniRenderComponent();
    if (ret != nullptr && ret->init())
    {
        ret->initialize(strFileName);
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

CAniRenderComponent::CAniRenderComponent(void)
: m_pRenderer()
{

}

CAniRenderComponent::~CAniRenderComponent(void)
{
}

void CAniRenderComponent::initialize(const std::string& strFileName)
{
    m_pRenderer = spine::SkeletonAnimation::createWithFile(strFileName + ".json",
                                                           strFileName + ".atlas");
}

void CAniRenderComponent::setAnimation(const std::string& strAniName, const bool bLoop)
{
    m_pRenderer->setAnimation(0, strAniName, bLoop);
}

void CAniRenderComponent::onEnter()
{
}

void CAniRenderComponent::onExit()
{
}

void CAniRenderComponent::update(float delta)
{
}