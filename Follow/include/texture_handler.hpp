#ifndef TEXTURE_HANDLER_HPP
#define TEXTURE_HANDLER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#define NUMBER_OF_IMAGES (int)17

class TextureHandle
{
private:
    std::vector <std::string> Image;
    std::vector <sf::Texture> Texture;

    void InitializeImage();
    void InitializeTexture();
public:
    TextureHandle();
    virtual ~TextureHandle();

    std::vector <sf::Texture> GetTexture();
};

#endif