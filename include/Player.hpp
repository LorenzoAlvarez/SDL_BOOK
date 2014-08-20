/* 
 * File:   Player.hpp
 * Author: zito
 *
 * Created on 20 de agosto de 2014, 0:03
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "SDLGameObject.hpp"

class Player : public SDLGameObject 
{  //inherit form GameObject
  
public:
    
    Player(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif	/* PLAYER_HPP */

