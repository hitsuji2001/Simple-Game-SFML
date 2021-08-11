#ifndef __PADDLE__HPP__
#define __PADDLE__HPP__

#include <SFML/Graphics.hpp>

#include "window.hpp"
#include "object.hpp"

#define REGTANGLE_WIDTH 10.0f
#define REGTANGLE_HEIGTH WINDOW_HEIGHT / 7.0f
#define FIRST_PADDLE_POSITION sf::Vector2f((1.0f / 10.0f) * WINDOW_WIDTH - REGTANGLE_WIDTH, WINDOW_HEIGHT / 2.0f - REGTANGLE_HEIGTH / 2.0f)
#define SECOND_PADDLE_POSITION sf::Vector2f((9.0f / 10.0f) * WINDOW_WIDTH - REGTANGLE_WIDTH, WINDOW_HEIGHT / 2.0f - REGTANGLE_HEIGTH / 2.0f)
#define PADDLE_MOVEMENT_SPEED 3.5f

class Paddle : public Object
{
private:
    //Variables
    sf::RectangleShape v_Paddle;
    sf::Color PaddleColor;
private:
    //Objects

private:
    //Private Functions
    void IntializeVariables();
    void InitializePaddle();
public:
    //Constructors And Destructors
    Paddle();
    Paddle(sf::Vector2f originalPos);
    virtual ~Paddle();

public:
    //Getters
    sf::RectangleShape GetPaddleShape();
public:
    //Setters
public:
    //Public Functions:
    void Update();
    void ForceInBound(bool up, bool down);
    void Draw(sf::RenderTarget &target);
};

#endif