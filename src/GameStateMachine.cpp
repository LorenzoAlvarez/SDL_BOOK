/* 
 * File:   GameStateMachine.cpp
 * Author: zito
 * 
 * Created on 2 de septiembre de 2014, 0:06
 */

#include "GameStateMachine.hpp"

void GameStateMachine::pushState(GameState* pState)
{
    std::unique_ptr<GameState> temp(pState);
    m_gameStates.push_back(std::move(temp));
    m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->onExit())
        {
            m_gameStates.pop_back();
        }
    }
}

void GameStateMachine::changeState(GameState* pState)
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {
            return;
        }
        
        if(m_gameStates.back()->onExit())
        {
            m_gameStates.pop_back();
        }
        
    }
    //push back our new State
    std::unique_ptr<GameState> temp(pState);
    m_gameStates.push_back(std::move(temp));
    
    //initialise it
    m_gameStates.back()->onEnter();
    
}

void GameStateMachine::update()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->update();
    }
}

void GameStateMachine::render()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->render();
    }
}