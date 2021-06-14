#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "snake_body.hpp"
#include "mics.hpp"

class Snake
{
private:
    //Variables
    int length;
    std::vector <SnakeBody*> snakeBody;
    Direction facingDirection;

    //Resources

    //Private Function
    void initializeVariables();
public:
    //Constructers and Destructors
    Snake();
    ~Snake();

    //Getters
    int getLength();
    std::vector <SnakeBody*> getBody();

    //Setters
    void setLength(int length);

    //Functions
    void draw(sf::RenderWindow &window);
};

#endif