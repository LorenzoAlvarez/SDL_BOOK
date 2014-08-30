/* 
 * File:   SDL_ptr.hpp
 * Author: zito
 *
 * Estructura de archivos para crear punteros únicos 
 * 
 * https://github.com/DirtYiCE/mmmmmm/blob/master/sdl_ptr.hpp
 * 
 * Created on 14 de agosto de 2014, 1:56
 */

#ifndef SDL_PTR_HPP
#define	SDL_PTR_HPP

#include <memory>
#include <SDL2/SDL.h>

template <typename T, void (*Fun)(T*)>
struct FunDelete
{
    void operator()(T* ptr) const
    {
        Fun(ptr);
    }
};

typedef FunDelete<SDL_Window, SDL_DestroyWindow> WindowDeleter;
typedef std::unique_ptr<SDL_Window, WindowDeleter> WindowPtr;

typedef FunDelete<SDL_Renderer, SDL_DestroyRenderer> RendererDeleter;
typedef std::unique_ptr<SDL_Renderer, RendererDeleter> RendererPtr;

typedef FunDelete<SDL_Surface, SDL_FreeSurface> SurfaceDeleter;
typedef std::unique_ptr<SDL_Surface, SurfaceDeleter> SurfacePtr;

typedef FunDelete<SDL_Texture, SDL_DestroyTexture> TextureDeleter;
typedef std::unique_ptr<SDL_Texture, TextureDeleter> TexturePtr;

typedef FunDelete<SDL_Joystick, SDL_JoystickClose> JoystickDeleter;
typedef std::unique_ptr<SDL_Joystick, JoystickDeleter> JoystickPtr;

#endif	/* SDL_PTR_HPP */

