/* 
 * File:   TextureManager.hpp
 * Author: zito
 *
 * Created on 17 de agosto de 2014, 23:26
 */

#ifndef TEXTUREMANAGER_HPP
#define	TEXTUREMANAGER_HPP

#include "SDL_ptr.hpp"
#include <map>
#include <SDL2/SDL_image.h>
#include <iostream>


class TextureManager {
public:
    
    static TextureManager* Istance()
    {
        if(s_pIstance.get() == 0)
        {
            std::unique_ptr<TextureManager> temp(new TextureManager());
            s_pIstance = std::move(temp);
            return s_pIstance.get();
        }
        return s_pIstance.get();
    }
    
    /**
     * load
     * 
     * @param filename filename of the image we want to use
     * @param id ID we want to use to refer to the texture
     * @param pRenderer renderer we want to use
     * @return 
     */
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    
    /**
     * draw
     * 
     * @param id ID of the texture we want to draw
     * @param x the x and y position we want to draw
     * @param y
     * @param width height and width of the frame or the image we are using
     * @param height
     * @param pRenderer the renderer we will copy to
     * @param flip describe how we want the image to be displayed
     */
    void draw (std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void drawFrame(std::string id, int x, int y, int width, int height,
    int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    ~TextureManager();
    
private:
    
    std::map<std::string, TexturePtr> m_textureMap;
    
    TextureManager(){ }
    
    
    static std::unique_ptr<TextureManager> s_pIstance;
};

typedef TextureManager TheTextureManager;

#endif	/* TEXTUREMANAGER_HPP */

