/* 
 * File:   InputHandler.hpp
 * Author: zito
 *
 * Created on 27 de agosto de 2014, 0:01
 */

#ifndef INPUTHANDLER_HPP
#define	INPUTHANDLER_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "SDL_ptr.hpp"
#include "Game.hpp"

class InputHandler {
public:
    
    static InputHandler* Istance()
    {
        if(s_pIstance.get() == NULL)
        {
             std::unique_ptr<InputHandler> temp(new InputHandler());
            s_pIstance = std::move(temp);        
        }
        return s_pIstance.get();
    }
    
    void update();
    void clean();
    
    ~InputHandler() {}
    
    void initialiseJoysticks();
    bool joysticksInitialised() { return m_bJoysticksInitialised; }
    
    int xvalue (int joy, int stick);
    int yvalue (int joy, int stick);
    
private:
    
    std::vector<JoystickPtr> m_joysticks;
    bool m_bJoysticksInitialised;
    InputHandler();
    
    
    std::vector<std::pair<std::unique_ptr<Vector2D>, std::unique_ptr<Vector2D> > > m_joystickValues;
    const int m_joystickDeadZone = 10000;
    
    
    static std::unique_ptr<InputHandler> s_pIstance;

};

typedef InputHandler TheInputHandler;

#endif	/* INPUTHANDLER_HPP */

