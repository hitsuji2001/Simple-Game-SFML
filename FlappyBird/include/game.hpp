#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 600
#define MAX_FPS 60

class Game
{
private:
    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    sf::Event event;
    std::string title;

private:
    //Private Functions
    void initializeVariable();
    void initializeWindow();
public:
    //Constructors and Destructors
    Game();
    ~Game();
public:
    //Getter
    bool isRunning();
    void update();
    void render();
    void pollEvents();
public:
    //Setter

};

#endif