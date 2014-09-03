/* 
 * File:   PlayState.hpp
 * Author: zito
 *
 * Created on 2 de septiembre de 2014, 1:43
 */

#ifndef PLAYSTATE_HPP
#define	PLAYSTATE_HPP

#include <iostream>
#include "GameState.hpp"

class PlayState : public GameState {
public:
   
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const { return s_playID; }
    
private:
    
    static const std::string s_playID;

};

#endif	/* PLAYSTATE_HPP */

