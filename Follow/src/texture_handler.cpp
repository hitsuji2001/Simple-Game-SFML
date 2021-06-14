#include "../include/texture_handler.hpp"

TextureHandle::TextureHandle()
{
    this->InitializeImage();
    this->InitializeTexture();
}

TextureHandle::~TextureHandle()
{
    this->Image.clear();
    this->Texture.clear();
}

void TextureHandle::InitializeImage()
{
    for(int i = 1; i < NUMBER_OF_IMAGES + 1; i++)
    {
        std::string string = "";
        string += "img/";
        string += std::to_string(i);
        string += ".jpg";
        this->Image.push_back(string);
    }
}

void TextureHandle::InitializeTexture()
{
    for(int i = 0; i < this->Image.size(); i++)
    {
        sf::Texture texture;
        texture.loadFromFile(this->Image.at(i));
        this->Texture.push_back(texture);
    }
}

std::vector <sf::Texture> TextureHandle::GetTexture()
{
    return this->Texture;
}
