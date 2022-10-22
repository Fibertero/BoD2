#include"raylib.h"
#include"engine.hpp"

Window::Window(Vector2 _size, const char *_title, int _Fps):
    size(_size), title(_title), Fps(_Fps){
        InitWindow(size.x, size.y, title);
    }
int Window::GetX(){
    return size.x;
}
int Window::GetY(){
    return size.y;
}
int Window::GetFPS(){
    return Fps;
}
const char *Window::GetTitle(){
    return title;
}