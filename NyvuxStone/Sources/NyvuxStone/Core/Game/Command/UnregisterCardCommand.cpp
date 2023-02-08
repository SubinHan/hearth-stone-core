#include "pch.h"

#include "NyvuxStone/Core/Game/Command/UnregisterCardCommand.h"

nyvux::UnregisterCardCommand::UnregisterCardCommand(std::shared_ptr<nyvux::GameMediator> GameMediator)
{
	this->GameMediator = GameMediator;
}

void nyvux::UnregisterCardCommand::Execute(Event Event)
{
	GameMediator->UnregisterCard(Event.Target);
}
