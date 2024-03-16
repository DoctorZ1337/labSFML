#include <SFML/Graphics.hpp>
#include <Figures.hpp>
#include <Game.hpp>

int main()
{
    sz::Game game(600, 600, "Game :D");
    game.setupGame();

    game.LifeCycle();

    return 0;
}