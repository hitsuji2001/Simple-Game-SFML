#ifndef SNAKE_BODY_HPP
#define SNAKE_BODY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "mics.hpp"

class SnakeBody
{
private:
    //Variables
    sf::Vector2f position;
    bool isHead;

    //Resources
    sf::Texture texture;
    sf::Sprite sprite;

    //Private Function
    void initializeVariables();
    void initializeTexture();
    void initializeSprite();
public:
    //Contructors and Destructors
    SnakeBody();
    SnakeBody(bool isHead);
    ~SnakeBody();

    //Getters
    sf::Texture getTexture();
    sf::Sprite getSprite();
    sf::Vector2f getPosition();

    //Setters
    void setTexture(sf::Texture texture);
    void setSprite(sf::Sprite sprite);
    void setPosition(sf::Vector2f pos);

    //Function
    void drawToWindow(sf::RenderWindow &window);
    void move();
    void follow();
};

#endif