#include"raylib.h"
#include"src/camera.hpp"
#include"src/engine.hpp"
#include"src/city.hpp"
#include"src/store.hpp"
#include<iostream>
#define PLAYER_PATCH "res/player.png"

/*
Basic config
*/
typedef enum
{
    COMPANY=0,
    CITY,
    STORE,
    FOREST
} GameStates;

GameStates GameState = COMPANY; 

int main()
{
    /*Init the gameWindow*/
    auto GameWindow = Window((Vector2){800,600}, "Game", 60);
    //ToggleFullscreen();   

    /*Loading textures*/
    std::vector<const char *> CityTex{"../res/store.png", "../res/roadH.png", "../res/roadV.png", "../res/forest.png", "../res/motorbike.png", "../res/truck.png", "../res/plane.png"};
    std::vector<const char *> IndustryTex{"../res/worker.png", "../res/PlusWorker.png", "../res/wood.png"};
    std::vector<const char *> StoreTex{"../res/carIcon.png"};
    std::vector<const char *> ForestTex{"../res/lumberjack.png"};

    auto CityTextures = GameloadTextures(CityTex);
    auto IndustryTextures = GameloadTextures(IndustryTex);
    auto StoreTextures = GameloadTextures(StoreTex);
    auto ForestTextures = GameloadTextures(ForestTex);

    /*Init the game camera*/ 
    Camera2D camera = CreateCamera(GetMousePosition(), (Vector2){GameWindow.GetX(), GameWindow.GetY()}, 0.0f, 1.0f);

    /*Init the days counter*/
    Image WatchImg = LoadImage("../res/relogio.png");
    ImageResize(&WatchImg, 65, 65);
    Texture2D WatchTex = LoadTextureFromImage(WatchImg);
    UnloadImage(WatchImg);

    Timer DayTimer = {0,0};
    Timer* pTime = &DayTimer;
    StartTimer(pTime, 24);
    /**/

    /*Init the game player*/
    auto MainCompany = Company(0.0f);
    MainCompany.AddMoney(10000);
    MainCompany.sprite = IndustryTextures[0];
    Employee e1{1, 15, 30};
    MainCompany.AddEmployee(e1);
    /**/

    /*Init the player transport*/
    auto MainVehicle = Vehicle(MOTORCYCLE);


    /*Loading the city/industry/store (GUI) contents*/
    Texture2D City = LoadTexture("../res/city.png");
    Texture2D Industry = LoadTexture("../res/industry.png");
    Texture2D Store = LoadTexture("../res/store.png");


    /*Creating itens*/
    int WoodPrice = 30;

    /*Creating buttons/NPC's:*/

    /*Defines the button that change the game state(Store, City etc)*/
    Rectangle SwitchWorld = {0, 400, 50, 50};
    /*Defines the store button rectangle*/
    Rectangle StoreButton = {200, 300, 100, 100};
    /*Defines the forest button rectangle*/
    Rectangle ForestButton = {0, 100, CityTextures[3].width, CityTextures[3].height};
    /*Lumberjack rectangle*/
    Rectangle LumberjackRec = {GameWindow.GetX()/2, GameWindow.GetY()/2, ForestTextures[0].width, ForestTextures[0].height};

    while (!WindowShouldClose())
    {
        if(MainVehicle.GetState())
        {
            MainVehicle.Listener();
        }

        BeginDrawing();
            ClearBackground(ColorAlpha(BROWN, 0.5f));
            /*Drawing Money*/
            DrawText((std::to_string((int)MainCompany.GetMoney()).c_str()), 600, 30, 30, GREEN);
            /*Drawing Wood*/
            DrawTexture(IndustryTextures[2], 250, 10, WHITE);
            DrawText(std::to_string(MainCompany.GetWood()).c_str(), 250, IndustryTextures[2].height+10, 20, BLACK);
            /*Drawing day time*/
            DrawText((std::to_string(static_cast<int> (GetElapsed(*pTime)))).c_str(), 25, 30, 30, WHITE);
            DrawTexture(WatchTex, 5, 10, WHITE);
            /*Drawing the city && industry button*/
            if(GameState==COMPANY || GameState==STORE || GameState==FOREST){
                DrawTexture(City, 0, 400, WHITE);
            }
            else if(GameState==CITY){
                DrawTexture(Industry, 0, 400, WHITE);
            }

            BeginMode2D(camera);
                switch(GameState){
                    case COMPANY:
                    /*
                    Draws
                    */

                    /*Drawing Workers*/
                    for(std::size_t i{}; i<MainCompany.Employees.size(); i++){
                        MainCompany.Employees[i].Draw(MainCompany.sprite, i, i*100);
                    }
                    /*Drawing workers buy button*/
                    DrawTexture(IndustryTextures[1], 0, MainCompany.Employees.size()*100, WHITE);

                    /*
                    Events
                    */
                    /*Drawing workers buy button*/
                    if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), (Rectangle){0, MainCompany.Employees.size()*100, IndustryTextures[1].width, IndustryTextures[1].height}) && IsMouseButtonPressed(0)){
                        Employee e{1, 15, GetRandomValue(10,30), MainCompany.sprite};
                        MainCompany.AddEmployee(e);
                    }

                    if(CheckCollisionPointRec(GetMousePosition(), SwitchWorld) && IsMouseButtonPressed(0)){
                        GameState = CITY;
                    }                    
                    /**/
                        break;

                    case CITY:
                    /*
                    Draws
                    */


                    /*Drawing the store image IN THE CITY*/
                    DrawTexture(CityTextures[0], 200, 300, WHITE);
                    /*Drawing the road*/
                    for(register int i{}; i<15 /*15 it's a magic number, and can be modified*/; i++){
                        DrawTexture(CityTextures[1], (CityTextures[1].width*i) /*-550 it's a magic number, and can be modified*/, StoreButton.y+50, WHITE);
                        //DrawTexture(CityTextures[2], 300, (CityTextures[2].height*i-550)
                    }
                    /*Drawing the forest image IN THE CITY*/
                    DrawTexture(CityTextures[3], 0, 100, WHITE);
                    

                    /*Drawing the vehicle*/
                    if(MainVehicle.GetState()){
                        MainVehicle.Draw(((MainVehicle.GetVehicle()==MOTORCYCLE) ? CityTextures[4] : (MainVehicle.GetVehicle()==TRUCK) ? CityTextures[5] : CityTextures[6]), MainCompany.GetWoodPerDay());
                    }
                    

                    /*
                    Events
                    */
                    if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), (Rectangle){MainVehicle.GetPos().x, MainVehicle.GetPos().y, 50, 50})){
                        Color UpgradeCostColor = (MainCompany.GetMoney() >= 10000/*Upgrade vehicle price*/) ? GREEN : RED;
                        DrawRectangle(MainVehicle.GetPos().x-20, MainVehicle.GetPos().y-40, 160, 100, ColorAlpha(GRAY, 0.5f));
                        DrawText("Upgrade: US$10,000", MainVehicle.GetPos().x-20, MainVehicle.GetPos().y-40, 15, UpgradeCostColor);
                        DrawText(("Capacity: " + std::to_string(MainVehicle.GetCapacity()*2)).c_str(), MainVehicle.GetPos().x-20, MainVehicle.GetPos().y, 15, BLUE);

                        if(IsMouseButtonPressed(0)){ MainVehicle.UpgradeVehicle(); MainVehicle.AddCapacity(MainVehicle.GetCapacity()*2); MainCompany.RemoveMoney(10000);}
                    }
                    if(CheckCollisionPointRec(GetMousePosition(), SwitchWorld) && IsMouseButtonPressed(0)){
                        GameState = COMPANY;
                    }
                    if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), (Rectangle){/*200, 300 = Texture position*/200, 300, CityTextures[0].width, CityTextures[0].height}) && IsMouseButtonPressed(0)){
                        GameState = STORE;
                    }
                    if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), ForestButton) && IsMouseButtonPressed(0)){
                        GameState = FOREST;
                    }
                    break;

                    case STORE:
                    /*
                    Draws
                    */

                   /*
                   Events
                   */
                   if(CheckCollisionPointRec(GetMousePosition(), SwitchWorld) && IsMouseButtonPressed(0)){
                       GameState = CITY;
                    }
                    break;

                    case FOREST:
                    /*
                    Draws
                    */
                   /*Drawing the lumberjack*/
                   DrawTexture(ForestTextures[0], GameWindow.GetX()/2, GameWindow.GetY()/2, WHITE);

                    /*
                    Events
                    */
                   /*Switch world button*/
                    if(CheckCollisionPointRec(GetMousePosition(), SwitchWorld) && IsMouseButtonPressed(0)){
                        GameState = CITY;
                    }
                    /*Listening to Lumberjack*/
                    if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), LumberjackRec)){
                        DrawRectangle(300, 400, 500, 40, ColorAlpha(GRAY, 0.5f));
                        DrawText(("You are reciving " + std::to_string(MainCompany.GetWoodPerDay()) + " woods per day, for US$" + std::to_string(MainCompany.GetWoodPerDay()*WoodPrice) ).c_str() , 300, 400, 20, WHITE);
                        if(IsMouseButtonPressed(0) && MainVehicle.GetCapacity() > MainCompany.GetWoodPerDay()){
                            MainCompany.AddWoodPerDay(1);
                        }
                        else if (IsMouseButtonPressed(1)){
                            MainCompany.AddWoodPerDay(-1);
                        }
                    }
                    break;
                }
                /**/

                /*Updating the days*/
                if(TimerDone(*pTime)){
                    for(std::size_t i{}; i<MainCompany.Employees.size(); i++){
                        /*Pay the workers*/
                        MainCompany.RemoveMoney(MainCompany.Employees[i].Wage);
                        /*Add money X the worker level*/
                        MainCompany.AddMoney(MainCompany.Employees[i].MoneyPerWork*MainCompany.Employees[i].Level);
                        /*Use the wood*/
                        MainCompany.RemoveWood(MainCompany.Employees[i].Level);
                        std::cout << MainCompany.Employees[i].Level << '\n';
                        /*Recive the wood per day*/
                        MainCompany.AddWood(MainCompany.GetWoodPerDay());
                        /*Pay the wood per day*/
                        MainCompany.RemoveMoney(MainCompany.GetWoodPerDay()*WoodPrice /*30 is the starter price of wood*/);
                        /*Up the level of all employees*/
                        MainCompany.Employees[i].Level += 1;

                        MainVehicle.SetState(true);
                    }
                    StartTimer(pTime, 24);
                }

                if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), (Rectangle){0,0,10,10})){
                    DrawRectangle(0,0,50,50,WHITE);
                }
                /**/
                
                /*Camera Update*/
                if(IsKeyDown(KEY_A)) camera.target.x -= 1;
                if(IsKeyDown(KEY_D)) camera.target.x += 1;
                if(IsKeyDown(KEY_W)) camera.target.y -= 1;
                if(IsKeyDown(KEY_S)) camera.target.y += 1;
                
                /**/
                
            EndMode2D();
        EndDrawing();
    }
    CloseWindow();
    
}