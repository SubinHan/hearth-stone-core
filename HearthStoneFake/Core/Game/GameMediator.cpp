#include "GameMediator.h"

void nyvux::GameMediator::RegisterPlayers(std::shared_ptr<Player> PlayerA, std::shared_ptr<Player> PlayerB)
{
	this->PlayerA = PlayerA;
	this->PlayerB = PlayerB;
}
