/*
The Store it's working now!
02/10/2022
*/

#include"raylib.h"
#include"company.hpp"
#include<iostream>

typedef struct
{
    float price;
    Texture2D sprite;
    void (*itemFunc)(Company MainCompany);
    void Listen(Vector2 pos, Company MainCompany, Camera2D camera);
} Item;


/*
                    Itens
*/
void WorkerFunction(Company MainCompany);