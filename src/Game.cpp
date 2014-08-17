/* 
 * File:   Game.cpp
 * Author: zito
 * 
 * Created on 15 de agosto de 2014, 21:32
 */

#include "../include/Game.hpp"

Game::Game() {
    
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    //attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success \n";
        
        
        //init the window           // Mirar una mejor implementación de esto:
        WindowPtr win(SDL_CreateWindow(title,xpos,ypos,width,height,flags));
        m_pWindow = std::move(win);
        //---------------------------------------
        if( m_pWindow != nullptr ) // Window init success
        {
            std::cout << "Window creation success\n";
            RendererPtr rend(SDL_CreateRenderer(m_pWindow.get(), -1, 0));
            m_pRenderer = std::move(rend);
            
            if(m_pRenderer != nullptr) //renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer.get(), 255, 255, 255, 255);
            }
            
            else
            {
                std::cout << "renderer init fail\n";
                return false; //renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false;
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false;
    }
    
    std::cout << "init success\n";
    m_bRunning = true; //everything inited successfully
    
    return true;
}

void Game::update()
{
    
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer.get());
    SDL_RenderPresent(m_pRenderer.get());
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    m_pWindow.release();
    m_pRenderer.release();
    SDL_Quit;
}