#include"raylib.h"
#include<vector>
#include<iostream>
#define DEFAULT_PATH "../res/Images/"

std::vector<Texture2D> GameloadTextures(std::vector<const char *> textures);
void GameUnloadTextures(std::vector<Texture2D> textures);
