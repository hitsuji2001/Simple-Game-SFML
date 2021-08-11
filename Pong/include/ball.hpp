#ifndef __BALL_HPP__
#define __BALL_HPP__

#include <SFML/Graphics.hpp>

#include "window.hpp"
#include "object.hpp"
#include "paddle.hpp"

#define BALL_RADIUS 10.0f
#define CHANGING_SPEED 10

class Ball : public Object
{
private:
    //Variables
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
    sf::Color GetBallColor();
public:
    //Setters
    void SetBallColor(sf::Color &color);
public:
    //Public Functions:
    void Update();
    void ForceInbound(bool up, bool down, bool left, bool right);
    void Draw(sf::RenderTarget &target);

    bool HitTheTopOfTheScreen();
    bool HitTheBottomOfTheScreen();
    bool HitTheLeftOfTheScreen();
    bool HitTheRightOfTheScreen();
    bool HitTheEdgeOfTheScreen();
    bool CollideWithPaddle(Paddle &paddle);
    bool CollideWithBall(Ball ball);
    bool HitSomething(Paddle &paddle);
};

#endif