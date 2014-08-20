/* 
 * File:   GameObject.hpp
 * Author: zito
 *
 * Created on 19 de agosto de 2014, 23:56
 */

#ifndef GAMEOBJECT_HPP
#define	GAMEOBJECT_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "LoaderParams.hpp"

class GameObject {
public:
    
    virtual void draw ()  = 0;
    virtual void update() = 0;
    virtual void clean()  = 0;
    
protected:
    
    GameObject (const LoaderParams* pParams) {}
    //virtual ~GameObject() {}
    
    std::string m_textureID;
    
    int m_currentFrame;
    int m_currentRow;
    
    int m_x;
    int m_y;
    
    int m_width;
    int m_height;
    
private:
    
    
};

#endif	/* GAMEOBJECT_HPP */

