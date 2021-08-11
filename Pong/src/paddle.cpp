#include "../include/paddle.hpp"

//Private Functions
void Paddle::IntializeVariables()
{
    this->Position = sf::Vector2f(ORIGIN);
    this->Velocity = 3.5f;
    this->PaddleColor = sf::Color::White;
}

void Paddle::InitializePaddle()
{
    this->v_Paddle = sf::RectangleShape(sf::Vector2f(REGTANGLE_WIDTH, REGTANGLE_HEIGTH));

    this->v_Paddle.setPosition(this->Position);
    this->v_Paddle.setFillColor(this->PaddleColor);
}

//Constructors And Destructors
Paddle::Paddle()
{
    this->IntializeVariables();
    this->InitializePaddle();
}

Paddle::Paddle(sf::Vector2f originalPos)
{
    this->IntializeVariables();

    this->Position = originalPos;
    this->SetPosition(this->Position);

    this->InitializePaddle();
}

Paddle::~Paddle()
{

}

//Getters
sf::Vector2f Paddle::GetPosition()
{
    return this->Position;
}

float Paddle::GetVelocity()
{
    return this->Velocity;
}

//Setters
void Paddle::SetPosition(sf::Vector2f &pos)
{
    this->Position = pos;

    this->v_Paddle.setPosition(this->Position);
}

void Paddle::SetVelocity(float &vel)
{
    this->Velocity = vel;
}

//Public Functions:
void Paddle::ForceInBound(bool up, bool down)
{
    if(up)
    {
        if(this->Position.y <= 0.0f)
        {
            this->Position.y = 0.0f;
            this->SetPosition(this->Position);
        }
    }
    if(down)
    {
        if(this->Position.y >= WINDOW_HEIGHT - REGTANGLE_HEIGTH)
        {
            this->Position.y = WINDOW_HEIGHT - REGTANGLE_HEIGTH;
            this->SetPosition(this->Position);
        }
    }
}

void Paddle::MoveUp(float amount)
{
    this->Position.y -= amount;

    this->ForceInBound(true, false);

    this->SetPosition(this->Position);
}

void Paddle::MoveDown(float amount)
{
    this->Position.y += amount;

    this->ForceInBound(false, true);

    this->SetPosition(this->Position);
}

void Paddle::Draw(sf::RenderTarget &target)
{
    target.draw(this->v_Paddle);
}