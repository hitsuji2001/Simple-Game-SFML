#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#define MAX_ENEMIES 10
#define SPAWN_RATE (float) 10.f
#define MAX_HEATLTH 3
#define POINT_MODIFIERS 1

class Enemy
{
private:
    //Variables
    sf::Vector2f Position;
    sf::RectangleShape Shape;
    sf::Texture Texture;
    sf::Vector2f Size;
    sf::Color FillColor;
    sf::Color OutLineColor;
    float OutLineThickness;

    //Game Logic
    int Heath;
    int LevelOfHardness;
    int PointEarn;
public:
    //Constructors and Destructors
    Enemy();
    ~Enemy();

    //Getter
    sf::Vector2f GetPositon();
    sf::Texture GetTexture();
    sf::Vector2f GetSize();
    sf::Color GetFillColor();
    sf::Color GetOutLineColor();
    sf::FloatRect GetGlobalBound();
    float GetOutLineThickness();
    int GetHealth();
    int GetLevelOfHardness();
    int GetPointEarn();

    //Setter
    void SetPosition(sf::Vector2f pos);
    void SetTexture(sf::Texture texture);
    void SetSize(sf::Vector2f size);
    void SetFillColor(sf::Color color);
    void SetOutLineColor(sf::Color color);
    void SetOutLineThickness(float thickness);
    void SetHealth(int health);
    void SetLevelOfHardness(int level);
    void SetPointEarn(int point);

    //Function
    void InitializeVariables();
    void InitializeImage();
    void Draw(sf::RenderWindow &window);
    void Move(sf::Vector2f dir);
};

#endif