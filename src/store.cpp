/*
The Store it's working now!
02/10/2022
*/

#include"store.hpp"

void Item::Listen(Vector2 pos, Company MainCompany)
{
    DrawTexture(sprite, pos.x, pos.y, WHITE);

    if(CheckCollisionPointRec(GetMousePosition(), (Rectangle){pos.x, pos.y, sprite.width, sprite.height}) && IsMouseButtonPressed(0))
    {
        itemFunc(MainCompany);
        std::cout << "foi" << '\n';
    }
}
void WorkerFunction(Company MainCompany)
{
    /*Worker Generator*/
    int MinimumMoneyPerJob = 500;
    int MaximumMoneyPerJob = 3000;
    Employee e{1 /*Starter level*/,
    1000*MainCompany.Employees.size(), 
    GetRandomValue(MinimumMoneyPerJob*MainCompany.Employees.size(),
    MaximumMoneyPerJob*MainCompany.Employees.size()),
    MainCompany.sprite
    };
    MainCompany.AddEmployee(e);
    std::cout << "foi dnv, carai so foda" << '\n';
}
