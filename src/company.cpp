#include"company.hpp"
#include<iostream>
#include"stdio.h"
#include"raylib.h"

Company::Company(float _Money): Money(_Money){}

void Company::AddMoney(float _money){
    Money += _money;
}
void Company::RemoveMoney(float _money){
    Money -= _money;
}
void Company::AddEmployee(Employee _employee){
    Employees.push_back(_employee);
}

void Employee::Draw(Texture2D sprite, int x, int y){
    DrawTexture(sprite, x, y, WHITE);
    DrawText(("Level: " + std::to_string(Level)).c_str(), x-10, y-40, 20, WHITE);
}
float Company::GetMoney(){
    return Money;
}