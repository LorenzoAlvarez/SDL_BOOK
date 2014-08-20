/* 
 * File:   Player.cpp
 * Author: zito
 * 
 * Created on 20 de agosto de 2014, 0:04
 */

#include "Player.hpp"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    
}

void Player::draw()
{
    SDLGameObject::draw(); //we now use SDLGameObject
}

void Player::update()
{
    --m_x;
    m_currentFrame = int (((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
    
}
