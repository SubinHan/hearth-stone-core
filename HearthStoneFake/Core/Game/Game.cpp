#include "Game.h"

using namespace std;

nyvux::Game::Game()
	: PlayerA(make_shared<Player>(UserInteraction.ReadDeckPlayerA())),
	PlayerB(make_shared<Player>(UserInteraction.ReadDeckPlayerB())),
	GameMediator()
{

}
