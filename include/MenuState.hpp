/* 
 * File:   MenuState.hpp
 * Author: zito
 *
 * Created on 1 de septiembre de 2014, 1:06
 */

#ifndef MENUSTATE_HPP
#define	MENUSTATE_HPP

#include <iostream>
#include "GameState.hpp"

class MenuState : public GameState {
public:
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    ~MenuState() { }
    
    virtual std::string getStateID() const { return s_menuID; }
private:
    static const std::string s_menuID;
};

#endif	/* MENUSTATE_HPP */

