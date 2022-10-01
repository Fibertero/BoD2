#include"raylib.h"
#include<vector>
#include"days.hpp"

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
public:
    Texture2D sprite;
    std::vector<Employee> Employees;


    Company(float _Money);

    void AddMoney(float _money);
    void RemoveMoney(float _money);
    void AddEmployee(Employee _employee);
    float GetMoney();
};