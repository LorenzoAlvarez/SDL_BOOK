/* 
 * File:   TextureManager.cpp
 * Author: zito
 * 
 * Created on 17 de agosto de 2014, 23:26
 */

#include "../include/TextureManager.hpp"

std::unique_ptr<TextureManager>  TextureManager::s_pIstance = 0;


TextureManager::~TextureManager() {
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
    SurfacePtr pTempSurface(IMG_Load(fileName.c_str()));
    
    if(pTempSurface.get() == nullptr)
    {
        std::cout << "TEXTUREMANAGER: FAILED TO LOAD " << fileName << std::endl;
        return 0;
    }
    
    TexturePtr pTexture(SDL_CreateTextureFromSurface(pRenderer, pTempSurface.get()));
    
    //Everything went ok, add the texture to our list
    if(pTexture.get() != nullptr)
    {
        
        auto inserted = m_textureMap.insert(std::make_pair(id,std::move(pTexture)));
        return true;
    }
    
    //Reaching here means something went wrong
    return false;
    
}


void TextureManager::draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id].get(),
            &srcRect, &destRect, 0, 0, flip);
    
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x  = width * currentFrame;
    srcRect.y  = height* (currentRow -1);
    srcRect.w  = destRect.w = width;
    srcRect.h  = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id].get(),
            &srcRect, &destRect, 0, 0, flip);
}

