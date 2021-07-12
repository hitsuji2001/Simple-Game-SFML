#include "../include/game.hpp"

//Private Functions
void Game::initializeVariable()
{
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;

    this->window = nullptr;
    this->title = "Flappy Birb";
}

void Game::initializeWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, this->title, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(MAX_FPS);
}

//Constructors and Destructors
Game::Game()
{
    this->initializeVariable();
    this->initializeWindow();
}

Game::~Game()
{
    delete this->window;
}

//Getter
bool Game::isRunning()
{
    //Check if the game is running or not
    return this->window->isOpen();
}

void Game::update()
{
    //Update the game
    this->pollEvents();
}

void Game::render()
{
    //Render the game
    this->window->clear();

    //Draw objects

    //Display them on the window
    this->window->display();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case::sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            default:
                break;
        }
    }
    
}