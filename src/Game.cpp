/* 
 * File:   Game.cpp
 * Author: zito
 * 
 * Created on 15 de agosto de 2014, 21:32
 */

#include "../include/Game.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"


std::unique_ptr<Game>  Game::s_pIstance = 0;

Game::Game()
{
    
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
                SDL_SetRenderDrawColor(m_pRenderer.get(), 0,0, 0, 255);
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
    
    TheInputHandler::Istance()->initialiseJoysticks();
    
    std::unique_ptr<GameStateMachine> temp(new GameStateMachine());
    
    m_pGameStateMachine = std::move(temp);
    
    m_pGameStateMachine->changeState(new MenuState);
    
    TextureManager::Istance()->load("media/images/animate-alpha.png","animate",m_pRenderer.get());
    
    
    std::unique_ptr<GameObject> player(new Player(new LoaderParams(100,100,128,82,"animate")));
    m_gameObjects.push_back(std::move(player));
    
    std::unique_ptr<GameObject> enemy(new Enemy(new LoaderParams(200,200,128,82,"animate")));
    m_gameObjects.push_back(std::move(enemy));
    
    return true;
}

void Game::update()
{
    m_pGameStateMachine->update();
    
    /*
    for(auto i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i)
    {
        i->get()->update();
    }
    //m_go.update();
    //m_player.update();
    */
}

void Game::handleEvents()
{
    /*    
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
    */
    TheInputHandler::Istance()->update();
    
    if(TheInputHandler::Istance()->getButtonState(0,1))
    {
        m_pGameStateMachine->changeState(new PlayState);
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer.get());
    
    m_pGameStateMachine->render();
    
    /*
    for(auto i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i)
    {
        i->get()->draw();
    }
    */
    SDL_RenderPresent(m_pRenderer.get());
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    TheInputHandler::Istance()->clean();
    m_pWindow.release();
    m_pRenderer.release();
    SDL_Quit;
    m_bRunning = false;
}

