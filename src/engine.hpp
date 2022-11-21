/*
Engine file is the same as "globalFunctions.(cpp/hpp)"
*/

#include"raylib.h"
#define WARNING_MESSAGE RED

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

typedef enum
{
    MENU=0,
    OPTIONS,
    COMPANY,
    CITY,
    STORE,
    FOREST
} GameStates;


typedef struct
{
    const char *text;
    Color textColor;
    bool isActive;
    void SetInfo(const char *_text, Color _textColor);
    void DrawMessage();
    void Undefine();
}GlobalMessage;
