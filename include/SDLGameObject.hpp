/* 
 * File:   SDLGameObject.hpp
 * Author: zito
 *
 * Created on 21 de agosto de 2014, 0:14
 */

#ifndef SDLGAMEOBJECT_HPP
#define	SDLGAMEOBJECT_HPP


#include "GameObject.hpp"
#include "LoaderParams.hpp"
#include "Vector2D.hpp"


class SDLGameObject : public GameObject {

public:
    SDLGameObject(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
    
protected:
    
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    
    int m_width;
    int m_height;
    
    int m_currentRow;
    int m_currentFrame;
    
    std::string m_textureID;
};

#endif	/* SDLGAMEOBJECT_HPP */

