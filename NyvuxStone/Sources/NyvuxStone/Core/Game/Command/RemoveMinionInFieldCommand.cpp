#include "pch.h"

#include "NyvuxStone/Core/Game/Command/RemoveMinionInFieldCommand.h"

nyvux::RemoveMinionInFieldCommand::RemoveMinionInFieldCommand(std::shared_ptr<nyvux::Player> Player)
{
	this->Player = Player;
}

void nyvux::RemoveMinionInFieldCommand::Execute(std::shared_ptr<nyvux::NyvuxStoneEvent> Event)
{
	auto Minion = std::dynamic_pointer_cast<nyvux::Minion>(Event->TargetCard);
	if (!Minion)
		return;

	Event->CurrentPlayer = Player;
	Player->RemovePlaceableInField(Minion);
}
