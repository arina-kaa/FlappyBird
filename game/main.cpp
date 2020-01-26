#include "Game.h"

int main()
{
	srand(unsigned(time(nullptr)));
	Game game;
	game.DoGameLoop();
}
