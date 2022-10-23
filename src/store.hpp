/*
The Store it's working now!
02/10/2022
*/

#include"raylib.h"
#include"company.hpp"
#include<iostream>
#include"vehicle.hpp"

typedef struct
{
    float price;
    Texture2D sprite;
    void (*itemFunc)(Vehicle _vehicle);
    Vehicle v;
    void Listen(Vector2 pos, Company MainCompany, Camera2D camera);
} Item;


/*
                    Itens
*/
