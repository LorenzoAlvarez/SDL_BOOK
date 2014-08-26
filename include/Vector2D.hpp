/* 
 * File:   Vector2D.hpp
 * Author: zito
 *
 * Created on 22 de agosto de 2014, 0:02
 */

#ifndef VECTOR2D_HPP
#define	VECTOR2D_HPP

#include <math.h>

class Vector2D {
    
    friend Vector2D& operator+=(Vector2D& v1, Vector2D& v2)
    {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        
        return v1;
    }
    
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
    {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;
        
        return v1;
    }
    
public:
    Vector2D(float x, float y): m_x(x), m_y(y){}

    float getX() { return m_x; }
    float getY() { return m_y; }
    
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    
    float length() { return sqrt(m_x * m_x + m_y * m_y); }

    Vector2D operator+(const Vector2D& v2) const;
    
    Vector2D operator*(float scalar);
    Vector2D& operator*=(float scalar);
    
    Vector2D operator-(const Vector2D& v2) const;
    
    Vector2D operator/(float scalar);
    Vector2D operator/=(float scalar);
    
    void normalize();
    
private:
    float m_x;
    float m_y;
};

#endif	/* VECTOR2D_HPP */

