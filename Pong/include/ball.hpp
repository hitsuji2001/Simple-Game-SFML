#ifndef __BALL_HPP__
#define __BALL_HPP__

#include <SFML/Graphics.hpp>

#include "window.hpp"
#include "object.hpp"

#define BALL_RADIUS 10.0f
#define CHANGING_SPEED 10

class Ball : public Object
{
private:
    //Variables
    sf::Vector2f Position;
    sf::Vector2f Velocity;
    sf::Vector2f Acceleration;

    sf::CircleShape v_Ball;
    float BallRadius;
    sf::Color BallColor;
private:
    //Objects

private:
    //Private Functions
    void InitializeVariables();
    void InitializeBall();

public:
    //Constructors And Destructors
    Ball();
    virtual ~Ball();
public:
    //Getters
    sf::Vector2f GetPosition();
    sf::Vector2f GetVelocity();
    sf::Vector2f GetAcceleration();
    sf::Color GetBallColor();
public:
    //Setters
    void SetPosition(sf::Vector2f &pos);
    void SetVelocity(sf::Vector2f &vel);
    void SetAcceleration(sf::Vector2f &acc);
    void SetBallColor(sf::Color &color);
public:
    //Public Functions:
    void ForceInbound(bool up, bool down, bool left, bool right);
    void Move(sf::Vector2f vel);
    void MoveLeft(float amount);
    void MoveRight(float amount);
    void MoveUp(float amount);
    void MoveDown(float amount);
    void RandomMove();
    void FlipVectorVelocity();
    void Draw(sf::RenderTarget &target);
};

#endif