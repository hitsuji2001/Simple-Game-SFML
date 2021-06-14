#include "../include/player.hpp"

//Constructors and Destructors
Player::Player()
{
    this->initializeTexture();
    this->initializeSprite();
}

Player::~Player()
{

}

//Private Functions
void Player::initializeTexture()
{
    if(!this->texture.loadFromFile("img/spaceship.png"))
    {
        std::cout << "ERROR: Player::initializeTexture() -> Failed to load texture!" << std::endl;
    }
}

void Player::initializeSprite()
{
    this->sprite.setTexture(this->texture);

}

//Functions
void Player::update()
{

}

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}