#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
    //Variables

    //Resources
    sf::Texture texture;
    sf::Sprite sprite;

    //Private Functions
    void initializeTexture();
    void initializeSprite();
public:
    //Constructors and Destructors
    Player();
    virtual ~Player();

    //Function
    void update();
    void render(sf::RenderTarget &target);
};

#endif