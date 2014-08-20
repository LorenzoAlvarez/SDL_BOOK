/* 
 * File:   Game.hpp
 * Author: zito
 *
 * Created on 15 de agosto de 2014, 21:32
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include "SDL_ptr.hpp"
#include <iostream>
#include <vector>
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"


class Game {
public:
    
     static Game* Istance()
    {
        if(s_pIstance.get() == 0)
        {
            std::unique_ptr<Game> temp(new Game());
            s_pIstance = std::move(temp);
            return s_pIstance.get();
        }
        return s_pIstance.get();
    }
    
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    
    void update();
    void handleEvents();
    void clean();
    void render();
    
    bool isRunning() {return m_bRunning;}
    
    SDL_Renderer* getRenderer() {return m_pRenderer.get();} 
    
private:
    
    WindowPtr     m_pWindow;
    RendererPtr   m_pRenderer;
    std::vector<std::unique_ptr<GameObject> > m_gameObjects;
    
    Game();
    static std::unique_ptr<Game> s_pIstance;
    
    bool          m_bRunning;
    
    //variables del textureManager
    int m_currentFrame;
    
};

typedef Game TheGame;

#endif	/* GAME_HPP */

