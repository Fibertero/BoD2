/*
The Store it's working now!
02/10/2022
*/

#include"store.hpp"

void Item::Listen(Vector2 pos, Company MainCompany, Camera2D camera)
{
    DrawTexture(sprite, pos.x, pos.y, WHITE);

    if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), (Rectangle){pos.x, pos.y, sprite.width, sprite.height}) && IsMouseButtonPressed(0))
    {
        itemFunc(v);
    }
}