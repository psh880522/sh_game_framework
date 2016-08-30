//
//  Commander.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#ifndef Commander_hpp
#define Commander_hpp

#include "core.h"

NS_CORE_BEGIN

class IGameObject;
class CCommander : public cocos2d::Ref
{
public:
    CCommander(IGameObject* pOwner);
    virtual ~CCommander();
    
    virtual void initialize();
    virtual void update(float delta);
    virtual void actionCommand(const cocos2d::Value& value);

protected:
    CC_SYNTHESIZE_READONLY(IGameObject*, m_pOwner, Owner);
};

NS_CORE_END

#endif /* Commander_hpp */
