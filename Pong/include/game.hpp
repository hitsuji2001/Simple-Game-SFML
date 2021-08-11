#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SFML/Graphics.hpp>
#include <vector>

#include "window.hpp"
#include "ball.hpp"
#include "paddle.hpp"

#define NUMBER_OF_BALLS 100

class Game
{
private:
    //Variables
    sf::RenderWindow *Window;
    sf::VideoMode VideoMode;
    std::string Title;
    sf::Event Event;

private:
    //Private Functions
    void InitializeVariables();
    void InitializeWindow();
    void InitializeBall();
    void InitializePaddles();
private:
    //Objects
    
    //Balls
    // std::vector <Ball*> Balls;
    Ball *ball;

    //Paddle
    Paddle *Paddle_1;
    Paddle *Paddle_2;

public:
    //Constructors and Destructors
    Game();
    virtual ~Game();

public:
    //Public Functions
    void PollEvents();
    void Run();
    void Update();
    void Render();
};

#endif