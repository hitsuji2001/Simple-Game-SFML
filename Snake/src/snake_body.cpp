#include "../include/snake_body.hpp"

//Contructors and Destructors
SnakeBody::SnakeBody()
{
    this->initializeVariables();
    this->initializeTexture();
    this->initializeSprite();
}

SnakeBody::SnakeBody(bool isHead)
{
    this->initializeVariables();
    this->isHead = isHead;
    this->initializeTexture();
    this->initializeSprite();
}

SnakeBody::~SnakeBody()
{

}

//Private Functions
void SnakeBody::initializeVariables()
{
    this->position = sf::Vector2f(0.f, 0.f);
    this->isHead = false;
}

void SnakeBody::initializeTexture()
{
    if(!this->isHead) this->texture.loadFromFile("img/snake_body.png");
    else this->texture.loadFromFile("img/snake_head_up.png");
}

void SnakeBody::initializeSprite()
{
    this->sprite.setTexture(this->texture);
    if(this->isHead) this->sprite.setScale(0.05f, 0.05f);
    else this->sprite.setScale(0.25f, 0.25f);
}


//Getters
sf::Vector2f SnakeBody::getPosition()
{
    return this->position;
}

sf::Texture SnakeBody::getTexture()
{
    return this->texture;
}

sf::Sprite SnakeBody::getSprite()
{
    return this->sprite;
}

//Setters
void SnakeBody::setPosition(sf::Vector2f pos)
{
    this->position = pos;
    this->sprite.setPosition(this->position);
}

void SnakeBody::setTexture(sf::Texture texture)
{
    this->texture = texture;
    this->sprite.setTexture(this->texture);
}

void SnakeBody::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
    this->sprite.setTexture(this->texture);
}

//Function
void SnakeBody::drawToWindow(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

void SnakeBody::move()
{

}

void SnakeBody::follow()
{

}