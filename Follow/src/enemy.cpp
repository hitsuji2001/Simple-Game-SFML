#include "../include/enemy.hpp"
   
//Constructors and Destructors
Enemy::Enemy()
{
    this->InitializeVariables();
    // this->InitializeImage();
    // this->InitializeTexture();
    this->Shape.setPosition(Position);
    this->Shape.setSize(Size);
    // this->Shape.setFillColor(FillColor);
    this->Shape.setOutlineColor(OutLineColor);
    this->Shape.setOutlineThickness(OutLineThickness);

    // this->Texture.loadFromFile(Image.at(rand() % NUMBER_OF_IMAGES));
    // this->Shape.setTexture(&Texture);

    this->Heath = rand() % MAX_HEATLTH + 1;
    // switch (this->Heath)
    // {
    // case 1:
    //     this->SetFillColor(sf::Color::Green);
    //     break;
    // case 2:
    //     this->SetFillColor(sf::Color::Blue);
    //     break; 
    // case 3:
    //     this->SetFillColor(sf::Color::Red);
    //     break;
    // default:
    //     break;
    // }
    this->LevelOfHardness = this->Heath;
    this->PointEarn = this->LevelOfHardness * POINT_MODIFIERS;
}

Enemy::~Enemy()
{

}

//Getter
sf::Vector2f Enemy::GetPositon()
{
    return Position;
}

sf::Texture Enemy::GetTexture()
{
    return Texture;
}

sf::Vector2f Enemy::GetSize()
{
    return Size;
}

sf::Color Enemy::GetFillColor()
{
    return FillColor;
}

sf::Color Enemy::GetOutLineColor()
{
    return OutLineColor;
}

sf::FloatRect Enemy::GetGlobalBound()
{
    return this->Shape.getGlobalBounds();
}

float Enemy::GetOutLineThickness()
{
    return OutLineThickness;
}

int Enemy::GetHealth()
{
    return this->Heath; 
}

int Enemy::GetLevelOfHardness()
{
    return this->LevelOfHardness;
}

int Enemy::GetPointEarn()
{
    return this->PointEarn;
}


//Setter
void Enemy::SetPosition(sf::Vector2f pos)
{
    Position = pos;
    this->Shape.setPosition(Position);
}

void Enemy::SetTexture(sf::Texture texture)
{
    Texture = texture;
    this->Shape.setTexture(&Texture);
}

void Enemy::SetSize(sf::Vector2f size)
{
    Size = size;
    this->Shape.setSize(Size);
}

void Enemy::SetFillColor(sf::Color color)
{
    FillColor = color;
    this->Shape.setFillColor(FillColor);
}

void Enemy::SetOutLineColor(sf::Color color)
{
    OutLineColor = color;
    this->Shape.setOutlineColor(OutLineColor);
}

void Enemy::SetOutLineThickness(float thickness)
{
    OutLineThickness = thickness;
    this->Shape.setOutlineThickness(OutLineThickness);
}

void Enemy::SetHealth(int health)
{
    this->Heath = health;
}

void Enemy::SetLevelOfHardness(int level)
{
    this->LevelOfHardness = level;
}

void Enemy::SetPointEarn(int point)
{
    this->PointEarn = point;
}


//Function
void Enemy::InitializeVariables()
{
    this->Position = sf::Vector2f(0.f, 0.f);
    this->Size = sf::Vector2f(69.f, 69.f);
    this->FillColor = sf::Color::Green;
    this->OutLineColor = sf::Color::Cyan;
    this->OutLineThickness = 0.f;
}

void Enemy::Draw(sf::RenderWindow &window)
{
    /**
    @return void
    \brief Draw the enemy to \param window
    */ 
    
    window.draw(this->Shape);
}

void Enemy::Move(sf::Vector2f dir)
{
    sf::Vector2f currPos = this->GetPositon();
    currPos += dir;

    this->SetPosition(currPos);
}