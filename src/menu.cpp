#include "menu.hpp"
#include<iostream>
#include<cmath>

void DrawConfigureIcon(Texture2D sprite, Vector2 pos, GameStates &gs)
{
    DrawTexture(sprite, pos.x, pos.y, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){pos.x, pos.y, sprite.width, sprite.height}) && IsMouseButtonPressed(0))
    {
        gs = MENU;
    }
}

void DrawResumeButton(Rectangle rec, GameStates &gs)
{
    DrawRectangle(rec.x, rec.y, rec.width, rec.height, BROWN);
    DrawText("Resume", rec.x, rec.y+10, 30, BLACK);
    if (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(0))
    {
        gs = CITY;
    }
}
void DrawVolume(Rectangle rec, float& GlobalVolume)
{
    DrawText(("Volume: " + std::to_string(static_cast<int>(GlobalVolume*10))).c_str(), rec.x, rec.y, 20, WHITE);
    if(CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(0) && GlobalVolume<MAX_VOLUME){
        GlobalVolume += 0.1;
    }
    else if(CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(1) && GlobalVolume>0){
        GlobalVolume -= 0.1;
    }

}
void DrawLeaveButton(Rectangle rec);