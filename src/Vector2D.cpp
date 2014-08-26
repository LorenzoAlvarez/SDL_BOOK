/* 
 * File:   Vector2D.cpp
 * Author: zito
 * 
 * Created on 22 de agosto de 2014, 0:02
 */

#include "Vector2D.hpp"

Vector2D Vector2D::operator+(const Vector2D& v2) const
{
    return Vector2D(m_x + v2.m_y, m_y + v2.m_y);
}

Vector2D  Vector2D::operator*(float scalar)
{
    return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D& Vector2D::operator*=(float scalar)
{
    m_x *= scalar;
    m_y *= scalar;
    
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2) const
{
    return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D Vector2D::operator/(float scalar)
{
    return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D Vector2D::operator/=(float scalar)
{
    m_x /= scalar;
    m_y /= scalar;
    
    return *this;
}

void Vector2D::normalize()
{
    float l = length();
    
    if (l > 0) //we never want to attempt to divide by 0
    {
        (*this) *= 1 / l;    
    }
}