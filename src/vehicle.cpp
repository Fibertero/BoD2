#include"vehicle.hpp"

Vehicle::Vehicle(Vehicles _vehicle):vehicle(_vehicle)
{
    timer = 24.0f;
    Level = 1;
    switch(vehicle)
    {
        case MOTORCYCLE:
            Capacity = MINIMUM_VEHICLE_CAPACITY * (Level*1);
            break;
        case TRUCK:
            Capacity = MINIMUM_VEHICLE_CAPACITY * (Level*2);
        case PLANE:
            Capacity = MINIMUM_VEHICLE_CAPACITY * (Level*3);
    }
}

bool Vehicle::GetState(){
    return isActive;
}

void Vehicle::Draw(Texture2D texture, int WoodPerDay){
    DrawTexture(texture, pos.x, pos.y, WHITE);
    DrawText((std::to_string(WoodPerDay) + "/" + std::to_string(Capacity)).c_str(), pos.x, pos.y-10, 20, BROWN);
}

void Vehicle::Listener(){
    if (timer > 0.0f)
	{
		timer -= GetFrameTime();
		pos = Vector2Lerp((Vector2){100, 400}, (Vector2){0, 400}, 1-timer/3.0f);
    }
    else{
        timer = 24.0f;
    }
}

void Vehicle::SetState(bool state){
    isActive = state;
}

Vehicles Vehicle::GetVehicle(){
    return vehicle;
}

int Vehicle::GetCapacity(){
    return Capacity;
}

void Vehicle::SetVehicle(Vehicles _vehicle){
    vehicle = _vehicle;
}

void Vehicle::UpgradeVehicle(){
    vehicle = vehicle==MOTORCYCLE ? TRUCK : PLANE;
}

Vector2 Vehicle::GetPos(){
    return pos;
}

void Vehicle::AddCapacity(int _capacity){
    Capacity += _capacity;
}