/* 
 * File:   Enemy.cpp
 * Author: zito
 * 
 * Created on 20 de agosto de 2014, 16:47
 */

#include "Enemy.hpp"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    
}

void Enemy::draw()
{
   SDLGameObject::draw(); //we now use SDLGameObject
}

void Enemy::update()
{
    ++m_y;
    ++m_x;
    
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
    
}


