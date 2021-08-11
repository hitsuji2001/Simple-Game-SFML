#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <SFML/Graphics.hpp>

#include "window.hpp"

#define VECTOR_ORIGIN sf::Vector2f(0.0f, 0.0f)

class Object
{
private:
    //Variables
    sf::Vector2f Position;
    sf::Vector2f Velocity;
    sf::Vector2f Acceleration;

private:
    //Private Functions
    void InitializeVariables();

public:
    //Constructors And Destructors
    Object();
    virtual ~Object();

public:
    //Getters
    sf::Vector2f GetPosition();
    sf::Vector2f GetVelocity();
    sf::Vector2f GetAcceleration();

public:
    //Setters
    void SetPosition(sf::Vector2f pos);
    void SetVelocity(sf::Vector2f vel);
    void SetAcceleration(sf::Vector2f acc);

public:
    //Public Functions
    void MoveUp(float amount);
    void MoveDown(float amount);
    void MoveLeft(float amount);
    void MoveRight(float amount);
    void Move(sf::Vector2f vec);
    void RandomMove();
    void FlipVelocity();
    void FlipVelocityX();
    void FlipVelocityY();
};

#endif