#include "../include/ball.hpp"

//Private Functions
void Ball::InitializeVariables()
{
    this->BallRadius = BALL_RADIUS;
    this->BallColor = sf::Color(sf::Color::White);

    this->SetPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f - this->BallRadius, WINDOW_HEIGHT / 2.0f - this->BallRadius));
    this->SetVelocity(sf::Vector2f(1.f, 2.f));
    this->SetAcceleration(sf::Vector2f(ORIGIN));

}

void Ball::InitializeBall()
{
    this->v_Ball = sf::CircleShape(this->BallRadius);
    this->v_Ball.setPosition(this->GetPosition());
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
sf::Color Ball::GetBallColor()
{
    return this->BallColor;
}

//Setters
void Ball::SetBallColor(sf::Color &color)
{
    this->BallColor = color;
    this->v_Ball.setFillColor(this->BallColor);
}

//Public Functions:
void Ball::Update()
{
    this->ForceInbound(true, true, true, true);

    if(this->HitTheTopOfTheScreen() or this->HitTheBottomOfTheScreen()) this->FlipVelocityY();
    else if (this->HitTheLeftOfTheScreen() or this->HitTheRightOfTheScreen()) this->FlipVelocityX();

    this->v_Ball.setPosition(this->GetPosition());
}

void Ball::ForceInbound(bool up, bool down, bool left, bool right)
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
        if(this->GetPosition().y >= WINDOW_HEIGHT - this->BallRadius * 2)
        {
            pos.y = WINDOW_HEIGHT - this->BallRadius * 2.0f;
            this->SetPosition(pos);
        }
    }
    if(left)
    {
        if(this->GetPosition().x <= 0.0f)
        {
            pos.x = 0.0f;
            this->SetPosition(pos);
        }
    }
    if(right)
    {
        if(this->GetPosition().x >= WINDOW_WIDTH - this->BallRadius * 2)
        {
            pos.x = WINDOW_WIDTH - this->BallRadius * 2;
            this->SetPosition(pos);
        }
    }
}

void Ball::Draw(sf::RenderTarget &target)
{
    target.draw(this->v_Ball);
}

bool Ball::HitTheTopOfTheScreen()
{
    if(this->GetPosition().y <= 0.0f) return true;
    else return false;
}

bool Ball::HitTheBottomOfTheScreen()
{
    if(this->GetPosition().y >= WINDOW_HEIGHT - this->BallRadius * 2.0f) return true;
    else return false;
}

bool Ball::HitTheLeftOfTheScreen()
{
    if(this->GetPosition().x <= 0.0f) return true;
    else return false;
}

bool Ball::HitTheRightOfTheScreen()
{
    if(this->GetPosition().x >= WINDOW_WIDTH - this->BallRadius * 2.0f) return true;
    else return false;
}


bool Ball::HitTheEdgeOfTheScreen()
{
    if(this->HitTheTopOfTheScreen() or this->HitTheBottomOfTheScreen() or this->HitTheLeftOfTheScreen() or this->HitTheRightOfTheScreen()) return true; 
    else return false;
}

bool Ball::CollideWithPaddle(Paddle &paddle)
{
    if(this->v_Ball.getGlobalBounds().intersects(paddle.GetPaddleShape().getGlobalBounds())) return true;
    else return false;
}

bool Ball::HitSomething(Paddle &paddle)
{
    if(this->HitTheEdgeOfTheScreen() or CollideWithPaddle(paddle)) return true;
    else return false;
}