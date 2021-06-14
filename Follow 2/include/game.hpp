#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "player.hpp"

#define HEIGHT 640
#define WIDTH 800
#define MAX_FPS 60

class Game
{
private:
    //Variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    std::string title;
    sf::Event event;

    //Objects
    Player *player;

    //Private Function
    void initializeWindow();
    void initializePlayer();
public:
    //Contructors and Destructors
    Game();
    virtual ~Game();

    //Functions
    void pollEvent();
    void run();
    void update();
    void render();
};

#endif