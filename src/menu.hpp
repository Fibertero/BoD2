#include"raylib.h"
#include"engine.hpp"
#define MAX_VOLUME 1
#define MINIMUM_VOLUME 0

void DrawConfigureIcon(Texture2D sprite, Vector2 pos, GameStates& gs);
void DrawResumeButton(Rectangle rec, GameStates& gs);
void DrawVolume(Rectangle rec, float& GlobalVolume);
void DrawLeaveButton(Rectangle rec);