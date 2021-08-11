#include "../include/game.hpp"
#include "../include/window.hpp"
#include "../include/ball.hpp"

//Private Functions
void Game::InitializeVariables()
{
    this->Window = nullptr;
    this->ball = nullptr;
    this->Paddle_1 = nullptr;
    this->Paddle_2 = nullptr;

    this->VideoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->Title = "Ponggggggg";
}

void Game::InitializeWindow()
{
    this->Window = new sf::RenderWindow(this->VideoMode, this->Title, sf::Style::Close | sf::Style::Titlebar);
    this->Window->setFramerateLimit(MAX_FPS);
}

void Game::InitializeBall()
{
    this->ball = new Ball();

    // for(int i = 0; i < NUMBER_OF_BALLS; i++)
    // {
    //     Ball *ball = new Ball();
    //     this->Balls.push_back(ball);        
    // }
}

void Game::InitializePaddles()
{
    this->Paddle_1 = new Paddle(FIRST_PADDLE_POSITION);
    this->Paddle_2 = new Paddle(SECOND_PADDLE_POSITION);
}

//Constructors And Destructors
Game::Game()
{
    this->InitializeVariables();
    this->InitializeBall();
    this->InitializePaddles();
    this->InitializeWindow();
}

Game::~Game()
{
    delete this->ball;

    // for(auto &b : Balls)
    //     delete b;
    delete this->Paddle_1;
    delete this->Paddle_2;

    delete this->Window;
}

//Public Functions
void Game::PollEvents()
{
    while (this->Window->pollEvent(this->Event))
    {
        switch (this->Event.type)
        {
            case sf::Event::Closed:
                this->Window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->Event.key.code == sf::Keyboard::Escape)
                    this->Window->close();
                break;
            default:
                break;
        }
    }
}

void Game::Run()
{
    while (this->Window->isOpen())
    {
        this->Update();
        this->Render();
    }
}

void Game::Update()
{
    this->PollEvents();

    this->ball->Move(this->ball->GetVelocity());

    this->ball->FlipVectorVelocity();

    // this->ball->MoveLeft(1.1f);

    // for(auto &b : Balls)
    //     b->RandomMove();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) this->Paddle_1->MoveUp(this->Paddle_1->GetVelocity());
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) this->Paddle_1->MoveDown(this->Paddle_1->GetVelocity());
}

void Game::Render()
{
    this->Window->clear();

    //Draw Objects

    //Draw Ball
    this->ball->Draw(*this->Window);

    // for(auto &ball : Balls)
    // {
    //     int r = rand() % 256;
    //     int g = rand() % 256;
    //     int b = rand() % 256;

    //     sf::Color color(r, g, b);

    //     ball->SetBallColor(color);
    //     ball->Draw(*this->Window);
    // }

    //Draw Paddles
    this->Paddle_1->Draw(*this->Window);
    this->Paddle_2->Draw(*this->Window);

    this->Window->display();
}