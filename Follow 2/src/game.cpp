#include "../include/game.hpp"

//Contructors and Destructors
Game::Game()
{
    this->initializeWindow();
    this->initializePlayer();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
}

//Private Functions
void Game::initializeWindow()
{
    this->videoMode.width = WIDTH;
    this->videoMode.height = HEIGHT;

    this->title = "Swaglord of Space";

    this->window = new sf::RenderWindow(this->videoMode, this->title, sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(MAX_FPS);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initializePlayer()
{
    this->player = new Player();
}

//Functions
void Game::pollEvent()
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

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Game::update()
{
    this->pollEvent();
}

void Game::render()
{
    this->window->clear();

    //Draw objects
    this->player->render(*this->window);

    this->window->display();
}