/*
The Store it's working now!
02/10/2022
*/

#include"store.hpp"

void Item::Listen(Vector2 pos, Company MainCompany, Camera2D camera)
{
    DrawTexture(sprite, pos.x, pos.y, WHITE);

    if(CheckCollisionPointRec(GetMousePosition(), (Rectangle){pos.x, pos.y, sprite.width, sprite.height}) && IsMouseButtonPressed(0))
    {
        itemFunc(MainCompany);
    }
}
void WorkerFunction(Company MainCompany)
{
    /*Worker Generator*/
    int MinimumMoneyPerJob = 500;
    int MaximumMoneyPerJob = 3000;
    Employee e{1, 1000, MainCompany.Employees.size()*10000, MainCompany.sprite};
    MainCompany.AddEmployee(e);
}

/*
typedef struct{
    int Level;
    int Wage;
    float MoneyPerWork;
    Texture2D Sprite;
    void Draw(Texture2D sprite, int x, int y);
}Employee;
*/