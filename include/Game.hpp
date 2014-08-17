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

class Game {
public:
    
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    
    void update();
    void handleEvents();
    void clean();
    void render();
    
    bool isRunning() {return m_bRunning;}
    
    Game();
    Game(const Game& orig);
    virtual ~Game();
private:
    WindowPtr     m_pWindow;
    RendererPtr   m_pRenderer;
    
    bool          m_bRunning;
    
    
};

#endif	/* GAME_HPP */

