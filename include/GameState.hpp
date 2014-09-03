/* 
 * File:   GameState.hpp
 * Author: zito
 *
 * Created on 1 de septiembre de 2014, 1:00
 */

#ifndef GAMESTATE_HPP
#define	GAMESTATE_HPP

#include <string>

class GameState {
public:

    virtual void    update()    = 0;
    virtual void    render()    = 0;
    
    virtual bool    onEnter()   = 0;
    virtual bool    onExit()    = 0;
    
    virtual std::string getStateID() const = 0;
    
    virtual  ~GameState() {} 
private:

};

#endif	/* GAMESTATE_HPP */

