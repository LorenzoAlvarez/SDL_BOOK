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
    
    Game* g_game = new Game();
    
    //inicializar SDL
    g_game->init("Chapter1",100,100,640,480,0);
    
    //bucle
    while(g_game->isRunning())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    
    g_game->clean();
    
    return 0;
}