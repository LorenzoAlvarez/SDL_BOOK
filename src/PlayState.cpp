/* 
 * File:   PlayState.cpp
 * Author: zito
 * 
 * Created on 2 de septiembre de 2014, 1:43
 */

#include "PlayState.hpp"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
    
}

void PlayState::render()
{
    
}

bool PlayState::onEnter()
{
    std::cout << "entering PlayState\n";
    return true;
}

bool PlayState::onExit()
{
    std::cout << "exiting PlayState\n";
}
