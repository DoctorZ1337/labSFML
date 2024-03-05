#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>

int main()
{
    sz::Game game(1600, 900, "Game :D");
    game.setupGame();

    game.LifeCycle();


    return 0;
}