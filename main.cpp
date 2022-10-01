#include"raylib.h"
#include"src/camera.hpp"
#include"src/engine.hpp"
#include"src/company.hpp"
#include<iostream>
#define PLAYER_PATCH "res/player.png"

/*
Basic config
*/
typedef enum
{
    COMPANY=0,
    CITY,
    STORE
} GameStates;
GameStates GameState = COMPANY; 

int main()
{
    /*Init the gameWindow*/
    auto GameWindow = Window((Vector2){800,600}, "Game", 60);
    //ToggleFullscreen();

    /*Init the game camera*/ 
    Camera2D camera = CreateCamera(GetMousePosition(), (Vector2){GameWindow.GetX()/static_cast<int>(2.0f), GameWindow.GetY()/static_cast<int>(2.0f)}, 1.0f, 1.0f);

    /*Init the days counter*/
    Image WatchImg = LoadImage("../res/relogio.png");
    ImageResize(&WatchImg, 65, 65);
    Texture2D WatchTex = LoadTextureFromImage(WatchImg);
    UnloadImage(WatchImg);

    Timer DayTimer = {0,0};
    Timer* pTime = &DayTimer;
    StartTimer(pTime, 20);
    /**/

    /*Init the game player*/
    auto MainCompany = Company(0.0f);
    Employee e1{2, 10000, 30};
    MainCompany.AddEmployee(e1);

    /*Loading the city/industry/store (GUI) contents*/
    Image CityImg = LoadImage("../res/cidade.png");
    Image IndustryImg = LoadImage("../res/industry.png");
    Image StoreImg = LoadImage("../res/store.png");
    ImageResize(&CityImg, 50, 50);
    ImageResize(&IndustryImg, 50, 50);
    ImageResize(&StoreImg, 100, 100);
    Texture2D City = LoadTextureFromImage(CityImg);
    Texture2D Industry = LoadTextureFromImage(IndustryImg);
    Texture2D Store = LoadTextureFromImage(StoreImg);
    UnloadImage(CityImg);
    UnloadImage(IndustryImg);
    UnloadImage(StoreImg);
    /*Defines the button that change the game state(Store, City etc)*/
    Rectangle SwitchWorld = {0, 400, 50, 50};
    /*Defines the store button rectangle*/
    Rectangle StoreButton = {200, 300, 100, 100};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(ColorAlpha(BROWN, 0.5f));
            /*Drawing Money*/
            DrawText((std::to_string(MainCompany.GetMoney()).c_str()), 400, 30, 30, GREEN);
            /*Drawing day time*/
            DrawText((std::to_string(static_cast<int> (GetElapsed(*pTime)))).c_str(), 25, 30, 30, WHITE);
            DrawTexture(WatchTex, 5, 10, WHITE);
            /*Drawing the city && industry button*/
            if(GameState==COMPANY || GameState==STORE){
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

                    /*
                    Events
                    */
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
                    DrawTexture(Store, 200, 300, WHITE);

                    /*
                    Events
                    */
                    if(CheckCollisionPointRec(GetMousePosition(), SwitchWorld) && IsMouseButtonPressed(0)){
                        GameState = COMPANY;
                    }
                    if(CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera), StoreButton) && IsMouseButtonPressed(0)){
                        GameState = STORE;
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
                }
                /**/

                /*The clicker system*/
                if(IsMouseButtonPressed(0)){
                    MainCompany.AddMoney(80);
                }
                /**/

                /*Updating the days*/
                if(TimerDone(*pTime)){
                    for(std::size_t i{}; i<MainCompany.Employees.size(); i++){
                        MainCompany.RemoveMoney(MainCompany.Employees[i].Wage);
                        /*Add money X the worker level*/
                        MainCompany.AddMoney(MainCompany.Employees[i].MoneyPerWork*MainCompany.Employees[i].Level);
                    }
                    StartTimer(pTime, 20);
                }
                /**/
                
                /*Camera Update*/
                if(IsMouseButtonDown(1)){
                    camera.target = GetMousePosition();
                }
                /**/
                
            EndMode2D();
        EndDrawing();
    }
    CloseWindow();
    
}