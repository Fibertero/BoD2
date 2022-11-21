#include"raylib.h"
#include<vector>

typedef struct{
    int Level;
    int Wage;
    float MoneyPerWork;
    Texture2D Sprite;
    void Draw(Texture2D sprite, int x, int y);
}Employee;

class Company{
private:
    float Money;
    int Wood;
    int WoodPerDay;
public:
    Texture2D sprite;
    std::vector<Employee> Employees;

    Company(float _Money);

    void AddMoney(float _money);
    void RemoveMoney(float _money);
    float GetMoney();

    void AddEmployee(Employee _employee);

    void AddWood(int _wood);
    void RemoveWood(int _wood);
    int GetWood();

    void AddWoodPerDay(int _amount);
    int GetWoodPerDay();
};