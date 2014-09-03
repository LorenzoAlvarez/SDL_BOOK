/* 
 * File:   GameStateMachine.hpp
 * Author: zito
 *
 * Created on 2 de septiembre de 2014, 0:06
 */

#ifndef GAMESTATEMACHINE_HPP
#define	GAMESTATEMACHINE_HPP

#include <memory>
#include <vector>
#include "GameState.hpp"

class GameStateMachine {
public:

    /**
     * add a state without removing the previous state
     * @param pState
     */
    void pushState(GameState* pState);
    /**
     * remove the previous state before adding another
     * @param pState
     */
    void changeState(GameState* pState);
    /**
     * remove whichever state is currently being used without adding another
     */
    void popState();
    
    ~GameStateMachine() { m_gameStates.clear(); }
    
    void update();
    
    void render();
    
private:
    
    std::vector<std::unique_ptr<GameState> > m_gameStates;
    
};

#endif	/* GAMESTATEMACHINE_HPP */

