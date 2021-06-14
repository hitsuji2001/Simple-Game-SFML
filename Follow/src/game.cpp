#include "../include/game.hpp"
#include "../include/enemy.hpp"
#include "../include/texture_handler.hpp"

//Contructors and Destructors
Game::Game()
{
    this->InitializeVariables();
    this->InitializeWindow();
    this->InitializeFonts();
    this->InitializeText();
    this->InitializeTexture();
    this->InitializeEnemies();
}

Game::~Game()
{
    delete this->window;

    delete this->textureHandle;

    for(auto &e : this->Enemies)
    {
        delete e;
    }
}

//Functions
void Game::PollEvents()
{
    while(this->window->pollEvent(this->Event))
    {
        switch (this->Event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->Event.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        default:
            break;
        }
    }
}

void Game::UpdateMousePosition()
{
    /**
        @return void

        Updates mouse position realative to the window
    */

   this->MousePositionRealativeToWindow = sf::Mouse::getPosition(*this->window);
   this->MousePositionRealativeToView = this->window->mapPixelToCoords(this->MousePositionRealativeToWindow);
}

void Game::UpdateText()
{
    std::stringstream ss;

    ss << "Point: " << this->Points << std::endl << "Health: " << this->Health << std::endl;

    if(this->Points == 69 or this->Points == 96) ss << "Nice!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

    this->UIText.setString(ss.str());
    this->UIText.setFillColor(sf::Color::Magenta);
}

void Game::UpdateEnemy()
{
    if(this->Enemies.size() < this->MaxEnemies)
    {
        if(this->EnemySpawnTimer >= this->EnemySpawnTimerMax)
        {
            this->SpawnEnemy();
            EnemySpawnTimer = 0.0f;
        }
        else EnemySpawnTimer += 1.0f;
    }

    //Move and update the enemies
    for(int i = 0; i < Enemies.size(); i++)
    {
        this->Enemies.at(i)->Move(sf::Vector2f(0.f, SPEED));
        
        //Check if the enemy has gone below the screen
        if(this->Enemies.at(i)->GetPositon().y > this->window->getSize().y)
        {
            this->Enemies.erase(this->Enemies.begin() + i);
            this->Health -= 1;
        }
    }

    //Check if the enemy has been clicked on
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
    {
        if(this->IsMouseHeld == false)
        {
            this->IsMouseHeld = true;
            bool deleted = false;
            for(int i = 0; i < this->Enemies.size() and !deleted; i++)
            {
                sf::Color currColor = this->Enemies.at(i)->GetFillColor();

                if(this->Enemies.at(i)->GetGlobalBound().contains(this->MousePositionRealativeToView))
                {
                    this->Enemies.at(i)->SetHealth(this->Enemies.at(i)->GetHealth() - 1);
                    this->Enemies.at(i)->SetFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                }
                if(this->Enemies.at(i)->GetHealth() == 0)
                {
                    //Delete the enemy
                    deleted = true;
                    this->Enemies.erase(this->Enemies.begin() + i);

                    //Gain points
                    this->Points += this->Enemies.at(i)->GetPointEarn();
                }
            }
        }
    }
    else this->IsMouseHeld = false;
}

void Game::SpawnEnemy()
{
    Enemy *enemy = new Enemy;
    enemy->SetPosition(sf::Vector2f(static_cast <float> (rand() % static_cast <int> (this->window->getSize().x - enemy->GetSize().x)), 0.f));
    enemy->SetTexture(this->textureHandle->GetTexture().at(rand() % NUMBER_OF_IMAGES));
    this->Enemies.push_back(enemy);
}

void Game::Update()
{
    this->PollEvents();
    if(this->EndGame == false)
    {
        this->UpdateMousePosition();
        this->UpdateEnemy();
        this->UpdateText();
    }
    if(this->Health <= 0) this->EndGame = true;
}

void Game::RenderEnemies()
{
    for(auto &e : Enemies)
    {
        e->Draw(*this->window);
    }
}

void Game::RenderText(sf::RenderTarget &target)
{
    target.draw(this->UIText);
}

void Game::Render()
{
    /**
        @return void

        -clear old frame
        -render objects
        -display frame

        Render the game objects
    */
    this->window->clear();

    //Draw game objects
    for(auto &e : Enemies)
    {
        e->Draw(*this->window);
    }

    this->RenderText(*this->window);

    this->window->display();
}

//Getter
const bool Game::IsRunning() const
{
    return this->window->isOpen();
}

const int Game::GetTotalEnemies() const
{
    return Enemies.size();
}

const bool Game::IsEndGame() const
{
    return this->EndGame;
}

//Private Function
void Game::InitializeVariables()
{
    this->window = nullptr;
    Title = "Intense Clicker!";

    //Game Logic
    this->EnemySpawnTimerMax = SPAWN_RATE;
    this->EnemySpawnTimer = this->EnemySpawnTimerMax;
    this->MaxEnemies = MAX_ENEMIES;
    this->Points = 0;
    this->Health = 10;
    this->IsMouseHeld = false;
    this->EndGame = false;
}

void Game::InitializeWindow()
{
    this->VideoMode.height = HEIGHT;
    this->VideoMode.width = WIDTH;
    this->window = new sf::RenderWindow(this->VideoMode, this->Title, sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(FRAME_LIMIT);
}

void Game::InitializeEnemies()
{

}

void Game::InitializeFonts()
{
    if(this->Font.loadFromFile("font/Hanged-Letters.ttf"));
    else if(this->Font.loadFromFile("font/Montserrat-Regular.ttf"));
    else if(this->Font.loadFromFile("font/Bombing.ttf"));
}

void Game::InitializeText()
{
    this->UIText.setFont(Font);
    this->UIText.setCharacterSize(24);
    this->UIText.setFillColor(sf::Color::White);
    this->UIText.setString("String");
}

void Game::InitializeTexture()
{
    this->textureHandle = new TextureHandle;
}