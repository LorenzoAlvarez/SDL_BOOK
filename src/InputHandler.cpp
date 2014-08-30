/* 
 * File:   InputHandler.cpp
 * Author: zito
 * 
 * Created on 27 de agosto de 2014, 0:01
 */

#include "InputHandler.hpp"

std::unique_ptr<InputHandler>  InputHandler::s_pIstance = 0;

InputHandler::InputHandler()
{
    
}

void InputHandler::initialiseJoysticks()
{
    if( SDL_WasInit(SDL_INIT_JOYSTICK) == 0 )
    {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }
    
    if( SDL_NumJoysticks() > 0 )
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            JoystickPtr joy(SDL_JoystickOpen(i));
            
            if ( joy.get() != nullptr )
            {
                m_joysticks.push_back(std::move(joy));
                
                std::unique_ptr<Vector2D> stick1(new Vector2D((float)0, (float) 0));
                std::unique_ptr<Vector2D> stick2(new Vector2D((float)0, (float) 0));
                
                m_joystickValues.push_back(std::make_pair(
                        std::move(stick1),std::move(stick2)));
                
            }
            
            else
            {
                std::cout << SDL_GetError();
            }
        }
        
        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoysticksInitialised = true;
        
        std::cout << "Initialised "<< m_joysticks.size() << "joystick(s)";
    }
    else
    {
        m_bJoysticksInitialised = false;
    }
}

void InputHandler::clean()
{
    if(m_bJoysticksInitialised)
    {
        m_joysticks.clear();
    }
}

void InputHandler::update()
{
    SDL_Event event;
    
    while (SDL_PollEvent ( &event ) )
    {
        if(event.type == SDL_QUIT)
        {
            TheGame::Istance()->clean();
        }
        
        if (event.type == SDL_JOYAXISMOTION)
        {
            int whichOne = event.jaxis.which;
            //left stick move left or right
            
            if (event.jaxis.axis == 0)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setX(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setX(-1);
                }
                else
                {
                    m_joystickValues[whichOne].first->setX(0);
                }
            }
            
            //left stick move up or down
            if(event.jaxis.axis == 1)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setY(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setY(-1);
                }
                else
                {
                    m_joystickValues[whichOne].first->setY(0);
                }
            }
            
            //right stick move left or right
            if(event.jaxis.axis == 2)
            {
                if(event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setX(1);
                }
                
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setX(-1);
                }
                else
                {
                    m_joystickValues[whichOne].second->setX(0);
                }
            }
            
            //right stick move up or down
            if(event.jaxis.axis == 3)
            {
                if(event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setY(1);
                }
                
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setY(-1);
                }
                
                else
                {
                    m_joystickValues[whichOne].second->setY(0);
                }
            }
        }
    }
}

int InputHandler::xvalue(int joy, int stick)
{
    if ( m_joystickValues.size() > 0)
    {
        if ( stick == 1 )
        {
            return m_joystickValues[joy].first->getX();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second->getX();
        }
    }
    return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
    if (m_joystickValues.size() > 0)
    {
        if (stick == 1)
        {
            return m_joystickValues[joy].first->getY();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second->getY();
        }
    }
    return 0;
}