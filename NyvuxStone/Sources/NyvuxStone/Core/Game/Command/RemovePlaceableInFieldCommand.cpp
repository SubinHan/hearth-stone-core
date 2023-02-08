#include "pch.h"

#include "NyvuxStone/Core/Game/Command/RemovePlaceableInFieldCommand.h"

nyvux::RemovePlaceableInFieldCommand::RemovePlaceableInFieldCommand(std::shared_ptr<nyvux::Player> Player)
{
	this->Player = Player;
}

void nyvux::RemovePlaceableInFieldCommand::Execute(Event Event)
{
	auto Placeable = std::dynamic_pointer_cast<Character>(Event.Target);
	if (!Placeable)
		return;

	Player->RemovePlaceableInField(Placeable);
}
