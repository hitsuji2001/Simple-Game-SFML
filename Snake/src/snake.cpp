#include "../include/snake.hpp"
#include "../include/game.hpp"

//Constructers and Destructors
Snake::Snake()
{
    this->initializeVariables();
}

Snake::~Snake()
{
    for(auto &s : this->snakeBody)
    {
        delete s;
    }
    this->snakeBody.clear();
}

//Private Functions
void Snake::initializeVariables()
{
    length = 2;

    SnakeBody *head = new SnakeBody(true);
    head->setPosition(sf::Vector2f(static_cast <float> (WIDTH / 2), static_cast <float> (HEIGHT / 2)));

    SnakeBody *body1 = new SnakeBody();
    body1->setPosition(sf::Vector2f(static_cast <float> (WIDTH / 2), static_cast <float> (HEIGHT / 2) + head->getSprite().getScale().y));

    this->snakeBody.push_back(head);
    this->snakeBody.push_back(body1);

    this->facingDirection = Up;
}

//Getters
int Snake::getLength()
{
    return this->length;
}

std::vector <SnakeBody*> Snake::getBody()
{
    return this->snakeBody;
}

//Setters
void Snake::setLength(int length)
{
    this->length = length;
}

//Functions
void Snake::draw(sf::RenderWindow &window)
{
    for(auto &s : snakeBody)
    {
        s->drawToWindow(window);
    }
}

void Snake::addBody()
{
    SnakeBody *body;
    body->setPosition(this->snakeBody.at(this->length - 1)->getPosition() + sf::Vector2f(25.f, 25.f));
    this->snakeBody.push_back(body);
    this->length++;
}