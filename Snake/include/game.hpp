#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "snake.hpp"

#define HEIGHT 600
#define WIDTH 800

#define MAX_FPS 60

class Game
{
private:
    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    sf::Event event;
    std::string title;

    //Ojects
    Snake *snake;

    //Private Functions
    void initializeWindow();
    void initializeVariable();
    void initializeSnake();
public:
    //Contructors and Destructors
    Game();
    ~Game();

    //Getters
    bool isRunning();

    //Functions
    void pollEvents();
    void update();
    void render();
};

#endif