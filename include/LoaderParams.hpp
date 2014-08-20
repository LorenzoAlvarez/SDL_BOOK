/* 
 * File:   LoaderParams.hpp
 * Author: zito
 *
 * Created on 20 de agosto de 2014, 23:26
 */

#ifndef LOADERPARAMS_HPP
#define	LOADERPARAMS_HPP

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID);

    int getX()      const {return m_x;}
    int getY()      const {return m_y;}
    int getWidth()  const {return m_width;}
    int getHeight() const {return m_height;}
    
    std::string getTextureID() const {return m_textureID;}
private:
    
    int m_x;
    int m_y;
    
    int m_width;
    int m_height;
    
    std::string m_textureID;
};

#endif	/* LOADERPARAMS_HPP */

