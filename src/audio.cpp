#include"audio.hpp"

void InitAudioSystem(int Volume){
    InitAudioDevice();
    SetMasterVolume(Volume);
}
void InitMusic(const char *file){
    Music MainTheme = LoadMusicStream(file);
    PlayMusicStream(MainTheme);
}
void PlayAudio(const char *sound){
    PlaySound(LoadSound(sound));
}
