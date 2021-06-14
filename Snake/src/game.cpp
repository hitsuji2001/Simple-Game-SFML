#include "../include/game.hpp"

//Contructors and Destructors
Game::Game()
{
    this->initializeVariable();
    this->initializeWindow();
    this->initializeSnake();
}

Game::~Game()
{
    delete this->window;
}

//Private Function
void Game::initializeWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, this->title, sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(MAX_FPS);
}

void Game::initializeVariable()
{
    this->window = nullptr;
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;
    this->title = "Snaek";
}

void Game::initializeSnake()
{
    this->snake = new Snake();
}

//Getters
bool Game::isRunning()
{
    return this->window->isOpen();
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    this->window->clear();

    //Draw objects
    this->snake->draw(*this->window);

    this->window->display();
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->event.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        default:
            break;
        }
    }
}