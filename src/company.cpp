#include"company.hpp"
#include<iostream>
#include"stdio.h"
#include"raylib.h"

Company::Company(float _Money): Money(_Money){
    Money = 0;
    Wood = 5;
    WoodPerDay = 0;
    

}

void Company::AddMoney(float _money){
    Money += _money;
}
void Company::RemoveMoney(float _money){
    Money -= _money;
}
void Company::AddEmployee(Employee _employee){
    Employees.push_back(_employee);
}
float Company::GetMoney(){
    return Money;
}


void Employee::Draw(Texture2D sprite, int x, int y){
    DrawTexture(sprite, x, y, WHITE);
    DrawText(("Level: " + std::to_string(Level)).c_str(), x-10, y-10, 20, WHITE);
}


void Company::AddWood(int _wood){
    Wood += _wood;
}
void Company::RemoveWood(int _wood){
    Wood -= _wood;
}
int Company::GetWood(){
    return Wood;
}

void Company::AddWoodPerDay(int _amount){
    WoodPerDay += _amount;
}
int Company::GetWoodPerDay(){
    return WoodPerDay;
}