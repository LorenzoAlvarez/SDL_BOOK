/* 
 * File:   MenuButton.hpp
 * Author: zito
 *
 * Created on 4 de septiembre de 2014, 23:58
 */

#ifndef MENUBUTTON_HPP
#define	MENUBUTTON_HPP

#include "SDLGameObject.hpp"

enum button_state
{
    MOUSE_OUT  = 0,
    MOUSE_OVER = 1,
    CLICKED    = 2
};

class MenuButton : public SDLGameObject {
public:
    
    MenuButton(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();

};

#endif	/* MENUBUTTON_HPP */

