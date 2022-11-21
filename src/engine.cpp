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

void GlobalMessage::Undefine(){
    text = "";
    textColor = WHITE;
    isActive=false;
}

void GlobalMessage::SetInfo(const char *_text, Color _textColor){
    text = _text;
    textColor = _textColor;
    isActive=true;
}

void GlobalMessage::DrawMessage(){
    /*Defining constants*/
    Vector2 textSize = MeasureTextEx(GetFontDefault(), text, 20, 2);
    Vector2 screenCenter = { GetScreenWidth() / 2, GetScreenHeight() / 2};
    Rectangle DoneButton = {GetScreenWidth()-100, GetScreenHeight()-50, 80, 40};

    if(isActive){
        /*Drawing "Done Button" box*/
        DrawRectangle(DoneButton.x, DoneButton.y, DoneButton.width, DoneButton.height, GREEN);
        /*Drawing "Done Button" text*/
        DrawText("OK", DoneButton.x+25, DoneButton.y+10, 25, BLACK);
        if(CheckCollisionPointRec(GetMousePosition(), DoneButton) && IsMouseButtonPressed(0)){
            Undefine();
        }

        /*Drawing text BOX*/
        DrawRectangle(0,500, 800, 200, ColorAlpha(GRAY, 0.5f));
        /*Drawing text INSIDE THE BOX*/
        DrawText(text, (screenCenter.x - textSize.x / 2) , (screenCenter.y - textSize.y / 2)+250, 20, textColor);
    }
}