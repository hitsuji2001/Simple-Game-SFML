#ifndef BIRD_HPP
#define BIRD_HPP

#include <SFML/Graphics.hpp>

#define JUMP_HEIGHT 50.f
#define FALL_SPEED 1.f

class Bird
{
private:
    //Variables
    float jumpHeight;
    float fallOffSpeed;
    sf::Vector2f position;
private:
    //Resources
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape debugShape;
private:
    //Private Functions
    void initializeVariables();
    void initializeTextures();
    void initializeSprites();
    void initializeDebugShape();
public:
    //Constructors and Destructors
    Bird();
    ~Bird();
public:
    //Getters
    sf::Vector2f getPosition();
public:
    //Setters
    void setPositon(sf::Vector2f pos);
public:
    //Public Functions
    void jump();
    void fall();
    void draw(sf::RenderTarget &renderTarget);
};

#endif