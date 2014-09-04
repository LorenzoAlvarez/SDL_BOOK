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
    m_velocity.setX(0);
    m_velocity.setY(0);
    
    handleInput();
    
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6 ));
    
    SDLGameObject::update();
}

void Player::clean()
{
    
}


void Player::handleInput()
{
    if (TheInputHandler::Istance()->joysticksInitialised())
    {
        if(TheInputHandler::Istance()->xvalue(0,1) > 0 ||
           TheInputHandler::Istance()->xvalue(0,1) < 0)
        {
            m_velocity.setX(1 * TheInputHandler::Istance()->xvalue(0,1));
        }
        
        if(TheInputHandler::Istance()->yvalue(0, 1) > 0 ||
           TheInputHandler::Istance()->yvalue(0, 1) < 0)
        {
            m_velocity.setY(1 * TheInputHandler::Istance()->yvalue(0, 1));
        }
        
        if(TheInputHandler::Istance()->xvalue(0, 2) > 0 ||
           TheInputHandler::Istance()->xvalue(0, 2) < 0)
        {
            m_velocity.setX(1 * TheInputHandler::Istance()->xvalue(0, 2));
        }
        
        if(TheInputHandler::Istance()->yvalue(0, 2) > 0 ||
           TheInputHandler::Istance()->yvalue(0, 2) < 0)
        {
            m_velocity.setY(1 * TheInputHandler::Istance() ->yvalue(0, 2));
        }
        
        if(TheInputHandler::Istance()->getButtonState(0, 3))
        {
            m_velocity.setX(1);
        }
        
    }
}