#include"city.hpp"

std::vector<Texture2D> GameloadTextures(std::vector<const char *> textures);std::vector<Texture2D> GameloadTextures(std::vector<const char *> textures)
{
    std::vector<Texture2D> t;
    for(std::size_t i{}; i<textures.size(); i++){
        Texture2D tex = LoadTexture(textures[i]);
        t.push_back(tex);
    }
    return t;
}