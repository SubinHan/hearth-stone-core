#include "NyvuxStone/Core/Game/Game.h"

using namespace std;

nyvux::Game::Game()
	: GameMediator(),
	PlayerA(make_shared<Player>(UserInteraction.ReadDeckPlayerA(), GameMediator)),
	PlayerB(make_shared<Player>(UserInteraction.ReadDeckPlayerB(), GameMediator))
{
	GameMediator->RegisterPlayers(PlayerA, PlayerB);
}
