#include "../include/paddle.hpp"

//Private Functions
void Paddle::IntializeVariables()
{
    this->SetPosition(sf::Vector2f(ORIGIN));
    this->SetVelocity(sf::Vector2f(0.0f, PADDLE_MOVEMENT_SPEED));
    this->PaddleColor = sf::Color::White;
}

void Paddle::InitializePaddle()
{
    this->v_Paddle = sf::RectangleShape(sf::Vector2f(REGTANGLE_WIDTH, REGTANGLE_HEIGTH));

    this->v_Paddle.setPosition(this->GetPosition());
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

    this->SetPosition(originalPos);
    this->SetPosition(this->GetPosition());

    this->InitializePaddle();
}

Paddle::~Paddle()
{

}

//Getters
sf::RectangleShape Paddle::GetPaddleShape()
{
    return this->v_Paddle;
}
//Setters

//Public Functions:
void Paddle::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->MoveUp(this->GetVelocity().y);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->MoveDown(this->GetVelocity().y);

    this->ForceInBound(true, true);

    this->v_Paddle.setPosition(this->GetPosition());
}

void Paddle::ForceInBound(bool up, bool down)
{
    sf::Vector2f pos = this->GetPosition();
    if(up)
    {
        if(this->GetPosition().y <= 0.0f)
        {
            pos.y = 0.0f;
            this->SetPosition(pos);
        }
    }
    if(down)
    {
        if(this->GetPosition().y >= WINDOW_HEIGHT - REGTANGLE_HEIGTH)
        {
            pos.y = WINDOW_HEIGHT - REGTANGLE_HEIGTH;
            this->SetPosition(pos);
        }
    }
}
void Paddle::Draw(sf::RenderTarget &target)
{
    target.draw(this->v_Paddle);
}