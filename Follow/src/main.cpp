#include "../include/game.hpp"

int main()
{
    srand(time(NULL));
    Game game;
    while(game.IsRunning() and !game.IsEndGame())
    {
        game.Update();
        game.Render();
    }
    return 0;
}