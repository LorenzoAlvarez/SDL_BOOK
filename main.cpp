/* 
 * File:   main.cpp
 * Author: zito
 *
 * Created on 14 de agosto de 2014, 1:51
 */

#include <cstdlib>
#include "include/Game.hpp"
using namespace std;

    const int FPS = 60;
    const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char** argv) {
    
    Uint32 frameStart, frameTime;
    
    std::cout << "game init attempt..." << endl;
    
    if(TheGame::Istance()->init("Chapter 1", 100, 100, 640, 480, false))
    {
        std::cout << "game init success!" << endl;
        
        while(TheGame::Istance()->isRunning())
        {
            frameStart = SDL_GetTicks();
            
            TheGame::Istance()->handleEvents();
            TheGame::Istance()->update();
            TheGame::Istance()->render();
            
            frameTime = SDL_GetTicks() - frameStart;
            
            if(frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    }
    else
    {
        std::cout << "game init failure - " << SDL_GetError() << endl;
        return -1;
    }
    
    std::cout << "game closing..." << endl;
    TheGame::Istance()->clean();
    
    return 0;
}