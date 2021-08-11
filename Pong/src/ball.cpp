#include "../include/ball.hpp"

//Private Functions
void Ball::InitializeVariables()
{
    this->BallRadius = BALL_RADIUS;
    this->BallColor = sf::Color(sf::Color::White);

    this->Position = sf::Vector2f(WINDOW_WIDTH / 2.0f - this->BallRadius, WINDOW_HEIGHT / 2.0f - this->BallRadius);
    this->Velocity = sf::Vector2f(1.f, 2.f);
    this->Acceleration = sf::Vector2f(ORIGIN);

}

void Ball::InitializeBall()
{
    this->v_Ball = sf::CircleShape(this->BallRadius);
    this->v_Ball.setPosition(this->Position);
    this->v_Ball.setFillColor(this->BallColor);
}
//Constructors And Destructors
Ball::Ball()
{
    this->InitializeVariables();
    this->InitializeBall();
}

Ball::~Ball()
{

}

//Getters
sf::Vector2f Ball::GetPosition()
{
    return this->Position;
}

sf::Vector2f Ball::GetVelocity()
{
    return this->Velocity;
}

sf::Vector2f Ball::GetAcceleration()
{
    return this->Acceleration;
}

sf::Color Ball::GetBallColor()
{
    return this->BallColor;
}

//Setters
void Ball::SetPosition(sf::Vector2f &pos)
{
    this->Position = pos;
    this->v_Ball.setPosition(this->Position);
}

void Ball::SetVelocity(sf::Vector2f &vel)
{
    this->Velocity = vel;
}

void Ball::SetAcceleration(sf::Vector2f &acc)
{
    this->Acceleration = acc;
}

void Ball::SetBallColor(sf::Color &color)
{
    this->BallColor = color;
    this->v_Ball.setFillColor(this->BallColor);
}

//Public Functions:
void Ball::ForceInbound(bool up, bool down, bool left, bool right)
{
    if(up)
    {
        if(this->Position.y <= 0.0f)
        this->Position.y = 0.0f;
    }
    if(down)
    {
        if(this->Position.y >= WINDOW_HEIGHT - this->BallRadius * 2)
        this->Position.y = WINDOW_HEIGHT - this->BallRadius * 2;
    }
    if(left)
    {
        if(this->Position.x <= 0.0f)
        this->Position.x = 0.0f;
    }
    if(right)
    {
        if(this->Position.x >= WINDOW_WIDTH - this->BallRadius * 2)
        this->Position.x = WINDOW_WIDTH - this->BallRadius * 2;
    }
}

void Ball::Move(sf::Vector2f vel)
{
    this->Position += vel;

    this->ForceInbound(true, true, true, true);

    this->SetPosition(this->Position);
}

void Ball::MoveLeft(float amount)
{
    this->Position.x -= amount;

    this->ForceInbound(false, false, true, false);

    this->SetPosition(this->Position);
}

void Ball::MoveRight(float amount)
{
    this->Position.x += amount;

    this->ForceInbound(false, false, false, true);

    this->SetPosition(this->Position);
}

void Ball::MoveUp(float amount)
{
    this->Position.y -= amount;

    this->ForceInbound(true, false, false, false);

    this->SetPosition(this->Position);
}

void Ball::MoveDown(float amount)
{
    this->Position.y += amount;

    this->ForceInbound(false, true, false, false);

    this->SetPosition(this->Position);
}

void Ball::RandomMove()
{
    int choice = rand() % 4;

    float amount = (rand() % MAX_FPS + 1) * (rand() % CHANGING_SPEED + 1) / MAX_FPS;

    switch (choice)
    {
        case 0:
            this->MoveUp(amount);
            break;
        case 1:
            this->MoveDown(amount);
            break;
        case 2:
            this->MoveLeft(amount);
            break;
        case 3:
            this->MoveRight(amount);
            break;
        default:
            break;
    }
}

void Ball::FlipVectorVelocity()
{
    if(this->Position.x <= 0 or this->Position.x >= WINDOW_WIDTH - this->BallRadius * 2)
    {
        this->Velocity.x = -this->Velocity.x;
        this->SetVelocity(this->Velocity);
    }
    if(this->Position.y <= 0 or this->Position.y >= WINDOW_HEIGHT - this->BallRadius * 2)
    {
        this->Velocity.y = -this->Velocity.y;
        this->SetVelocity(this->Velocity);
    }
}

void Ball::Draw(sf::RenderTarget &target)
{
    target.draw(this->v_Ball);
}