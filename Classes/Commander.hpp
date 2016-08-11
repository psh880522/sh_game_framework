//
//  Commander.hpp
//  sh_game_framework
//
//  Created by Challabros_Mac on 2016. 8. 11..
//
//

#ifndef Commander_hpp
#define Commander_hpp

#include "cocos2d.h"
#include "Macro.hpp"

NS_CORE_BEGIN

class IGameObject;
class Commander : public cocos2d::Ref
{
public:
    Commander(IGameObject* pOwner);
    virtual ~Commander();
    
    virtual void initialize();
    virtual void update(float delta);
    virtual void actionCommand(const cocos2d::Value& value);

protected:
    IGameObject* m_pOwner;
};

NS_CORE_END

#endif /* Commander_hpp */
