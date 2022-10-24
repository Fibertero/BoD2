#include"raylib.h"
#include"raymath.h"
#include<iostream>
#define MINIMUM_VEHICLE_CAPACITY 10

typedef enum{
    MOTORCYCLE=0,
    TRUCK,
    PLANE

}Vehicles;

class Vehicle
{
private:
    Vehicles vehicle;
    int Capacity;
    int Level;
    bool isActive;
    float timer;
    Vector2 pos;
public:
    Vehicle(Vehicles _vehicle);
    void Draw(Texture2D texture, int WoodPerDay);
    void Listener();
    bool GetState();
    void SetState(bool state);
    int GetCapacity();
    Vehicles GetVehicle();
    void SetVehicle(Vehicles _vehicle);
    void UpgradeVehicle();
    void AddCapacity(int _capacity);
    Vector2 GetPos();
};