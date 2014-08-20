/* 
 * File:   LoaderParams.cpp
 * Author: zito
 * 
 * Created on 20 de agosto de 2014, 23:26
 */

#include <string>

#include "LoaderParams.hpp"

LoaderParams::LoaderParams(int x, int y, int width, int height, std::string textureID) :
        m_x(x),
        m_y(y),
        m_width(width),
        m_height(height),
        m_textureID(textureID)
{
}


