#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>

#include "enemy.hpp"
#include "texture_handler.hpp"

#define HEIGHT 600
#define WIDTH 800
#define FRAME_LIMIT (unsigned int)60
#define SPEED (float) 0.69f

class Game
{
private:
    //Variable
    sf::RenderWindow *window;
    sf::VideoMode VideoMode;
    sf::Event Event;
    std::string Title;
    sf::Vector2i MousePositionRealativeToWindow;
    sf::Vector2f MousePositionRealativeToView; 

    //Resources 
    sf::Font Font;
    TextureHandle *textureHandle;

    //Text
    sf::Text UIText;

    //Game Logic
    int Points;
    float EnemySpawnTimer;
    float EnemySpawnTimerMax;
    unsigned int MaxEnemies;
    unsigned int Health;
    bool IsMouseHeld;
    bool EndGame;

    //Game Objects
    std::vector <Enemy*> Enemies;

    //Private Functions
    void InitializeVariables();
    void InitializeWindow();
    void InitializeEnemies();
    void InitializeFonts();
    void InitializeText();
    void InitializeTexture();
public:
    //Contructors and Destructors
    Game();
    virtual ~Game();

    //Functions
    void PollEvents();
    void UpdateMousePosition();
    void UpdateText();
    void UpdateEnemy();
    void SpawnEnemy();
    void Update();

    void RenderEnemies();
    void RenderText(sf::RenderTarget &target);
    void Render();

    //Getter
    const bool IsRunning() const;
    const int GetTotalEnemies() const;
    const bool IsEndGame() const;
};

#endif