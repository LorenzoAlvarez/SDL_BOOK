/* 
 * File:   MenuState.cpp
 * Author: zito
 * 
 * Created on 1 de septiembre de 2014, 1:06
 */

#include "MenuState.hpp"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
    
}

void MenuState::render()
{
    
}

bool MenuState::onEnter()
{
    std::cout << "Entering MenuState\n";
    return true;
}

bool MenuState::onExit()
{
    std::cout << "exiting MenuState\n";
    return true;
}

