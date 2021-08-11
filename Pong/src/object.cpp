#include "../include/object.hpp"

//Private Functions
void Object::InitializeVariables()
{
    this->Position = sf::Vector2f(ORIGIN);
    this->Velocity = VECTOR_ORIGIN;
    this->Acceleration = VECTOR_ORIGIN;
}

//Constructors And Destructors
Object::Object()
{

}

Object::~Object()
{

}
//Getters
sf::Vector2f Object::GetPosition()
{
    return this->Position;
}

sf::Vector2f Object::GetVelocity()
{
    return this->Velocity;
}

sf::Vector2f Object::GetAcceleration()
{
    return this->Acceleration;
}

//Setters
void Object::SetPosition(sf::Vector2f pos)
{
    this->Position = pos;
}

void Object::SetVelocity(sf::Vector2f vel)
{
    this->Velocity = vel;
}

void Object::SetAcceleration(sf::Vector2f acc)
{
    this->Acceleration = acc;
}

//Public Functions
void Object::MoveUp(float amount)
{
    this->Position.y -= amount;
    this->SetPosition(this->Position);
}

void Object::MoveDown(float amount)
{
    this->Position.y += amount;
    this->SetPosition(this->Position);
}

void Object::MoveLeft(float amount)
{
    this->Position.x -= amount;
    this->SetPosition(this->Position);
}

void Object::MoveRight(float amount)
{
    this->Position.x += amount;
    this->SetPosition(this->Position);
}

void Object::Move(sf::Vector2f vec)
{
    this->Position += vec;
    this->SetPosition(this->Position);
}

void Object::FlipVelocity()
{
    this->Velocity = -this->Velocity;
}

void Object::FlipVelocityX()
{
    this->Velocity.x = -this->Velocity.x;
}

void Object::FlipVelocityY()
{
    this->Velocity.y = -this->Velocity.y;
}
