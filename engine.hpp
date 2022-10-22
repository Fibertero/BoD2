#include"raylib.h"

class Window{
private:
    Vector2 size;
    const char *title;
    int Fps;
public:
    Window(Vector2 _size, const char *_title, int _Fps);
    int GetX();
    int GetY();
    int GetFPS();
    const char *GetTitle();
};