/* 
 * File:   SDLGameObject.cpp
 * Author: zito
 * 
 * Created on 21 de agosto de 2014, 0:14
 */

#include "SDLGameObject.hpp"
#include "LoaderParams.hpp"
#include "Game.hpp"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
    m_x = pParams->getX();
    m_y = pParams->getY();
    
    m_width     = pParams->getWidth();
    m_height    = pParams->getHeight();
    
    m_textureID = pParams->getTextureID();
    
    m_currentRow    = 1;
    m_currentFrame  = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Istance()->drawFrame(m_textureID, m_x, m_y, m_width,
            m_height, m_currentRow, m_currentFrame,
            TheGame::Istance()->getRenderer());
}

void SDLGameObject::clean()
{
    
}

void SDLGameObject::update()
{
    
}

