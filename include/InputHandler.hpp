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

enum mouse_buttons
{
    LEFT    = 0,
    MIDDLE  = 1,
    RIGHT   = 2
};

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
    
    ~InputHandler() 
    {
        m_joystickValues.clear();
        m_joysticks.clear();
        m_buttonStates.clear();
    }
    
    void initialiseJoysticks();
    bool joysticksInitialised() { return m_bJoysticksInitialised; }
    
    int xvalue (int joy, int stick);
    int yvalue (int joy, int stick);
    
    bool getButtonState(int joy, int buttonNumber)
    {
        return m_buttonStates[joy][buttonNumber];
    }
    
    bool getMouseButtonState(int buttonNumber)
    {
        return m_mouseButtonStates[buttonNumber];
    }
    
    Vector2D* getMousePosition()
    {
        return m_mousePosition.get();
    }
private:
    
    
    //JOYSTICK
    std::vector<JoystickPtr> m_joysticks;
    bool m_bJoysticksInitialised;
    InputHandler();
    
    
    
    std::vector<std::vector<bool> > m_buttonStates;
    std::vector<std::pair<std::unique_ptr<Vector2D>, std::unique_ptr<Vector2D> > > m_joystickValues;
    const int m_joystickDeadZone = 10000;
    
    
    //MOUSE
    std::vector<bool>           m_mouseButtonStates;
    std::unique_ptr<Vector2D>   m_mousePosition;
    
    
    
    static std::unique_ptr<InputHandler> s_pIstance;

};

typedef InputHandler TheInputHandler;

#endif	/* INPUTHANDLER_HPP */

