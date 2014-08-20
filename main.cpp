/* 
 * File:   main.cpp
 * Author: zito
 *
 * Created on 14 de agosto de 2014, 1:51
 */

#include <cstdlib>
#include "include/Game.hpp"
using namespace std;

int main(int argc, char** argv) {
    
    
    std::cout << "game init attempt..." << endl;
    
    if(TheGame::Istance()->init("Chapter 1", 100, 100, 640, 480, false))
    {
        std::cout << "game init success!" << endl;
        
        while(TheGame::Istance()->isRunning())
        {
            TheGame::Istance()->handleEvents();
            TheGame::Istance()->update();
            TheGame::Istance()->render();
            
            SDL_Delay(10);
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