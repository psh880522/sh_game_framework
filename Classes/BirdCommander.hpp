//
//  BirdCommander.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 25..
//
//

#ifndef BirdCommander_hpp
#define BirdCommander_hpp

#include "Commander.hpp"

class CBirdCommander : public core::CCommander
{
public:
    static CBirdCommander* create(core::IGameObject* pOwner);
    
    CBirdCommander(core::IGameObject* pOwner);
    virtual ~CBirdCommander();
    
    virtual void initialize();
    virtual void update(float delta);
    
private:
    float m_fDelayTime;
};

#endif /* BirdCommander_hpp */
