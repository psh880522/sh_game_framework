//
//  BirdCommander.cpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 25..
//
//

#include "BirdCommander.hpp"
#include "Bird.hpp"

USING_NS_CORE;
USING_NS_CC;

CBirdCommander *CBirdCommander::create(IGameObject* pOwner)
{
    CBirdCommander *ret = new (std::nothrow) CBirdCommander(pOwner);
    if (ret)
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

CBirdCommander::CBirdCommander(IGameObject* pOwner)
: CCommander(pOwner)
, m_fDelayTime()
{
    
}

CBirdCommander::~CBirdCommander()
{
    
}

void CBirdCommander::initialize()
{
}

void CBirdCommander::update(float delta)
{
    CCommander::update(delta);
    
    CGameObject* pOwner = dynamic_cast<CGameObject*>(getOwner());
    
    switch (pOwner->getCurrentState()) {
        case CBird::ST_IDLE:
        {
            m_fDelayTime += delta;
            
            if(m_fDelayTime >= random(5, 15))
            {
                m_fDelayTime = 0;
                
                Value command(CBird::CMD_MOVE);
                
                m_pOwner->actionCommand(command);
            }
        }break;
        default:
            break;
    }
}