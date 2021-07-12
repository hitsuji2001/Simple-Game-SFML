#include "../include/bird.hpp"

//Private Functions
void Bird::initializeVariables()
{
    this->jumpHeight = JUMP_HEIGHT;
    this->fallOffSpeed = FALL_SPEED;
    this->position = sf::Vector2f(69.f, 69.f);
}

void Bird::initializeTextures()
{

}

void Bird::initializeSprites()
{

}

void Bird::initializeDebugShape()
{
    this->debugShape = sf::RectangleShape(sf::Vector2f(69.f, 69.f));
    debugShape.setPosition(this->position);
}

//Constructors and Destructors
Bird::Bird()
{
    this->initializeVariables();
    this->initializeTextures();
    this->initializeSprites();
    this->initializeDebugShape();
}

Bird::~Bird()
{

}
//Getters
sf::Vector2f Bird::getPosition()
{
    return this->position;
}

//Setters
void Bird::setPositon(sf::Vector2f pos)
{
    this->position = pos;
    this->debugShape.setPosition(pos);
}

//Public Functions
void Bird::jump()
{
    sf::Vector2f currPosition = this->getPosition();
    this->setPositon(sf::Vector2f(currPosition.x, currPosition.y - this->jumpHeight));
}

void Bird::fall()
{
    sf::Vector2f currPosition = this->getPosition();
    this->setPositon(sf::Vector2f(currPosition.x, currPosition.y + this->fallOffSpeed));
}

void Bird::draw(sf::RenderTarget &renderTarget)
{
    renderTarget.draw(this->debugShape);
}
