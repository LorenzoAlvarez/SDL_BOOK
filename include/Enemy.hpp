/* 
 * File:   Enemy.hpp
 * Author: zito
 *
 * Created on 20 de agosto de 2014, 16:47
 */

#ifndef ENEMY_HPP
#define	ENEMY_HPP

#include "SDLGameObject.hpp"

class Enemy : public SDLGameObject {
public:

    //void load(int x, int y, int width, int height, std::string textureID);
    
    Enemy(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();

};

#endif	/* ENEMY_HPP */

