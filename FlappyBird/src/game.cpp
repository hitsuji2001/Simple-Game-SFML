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

void Game::initializeBird()
{
    this->bird = new Bird;
    this->bird->setPositon(sf::Vector2f(WIDTH / 10.f, HEIGHT / 2.5f));
}

//Constructors and Destructors
Game::Game()
{
    this->initializeVariable();
    this->initializeWindow();
    this->initializeBird();
}

Game::~Game()
{
    delete this->window;
    delete this->bird;
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

    //Make birb fall
    this->bird->fall();
}

void Game::render()
{
    //Render the game
    this->window->clear();

    //Draw objects
    this->bird->draw(*this->window);
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
                if(this->event.key.code == sf::Keyboard::Space or this->event.key.code == sf::Keyboard::Up)
                    this->bird->jump();
                break;
            default:
                break;
        }
    }
    
}