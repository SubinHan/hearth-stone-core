#include "pch.h"

#include "NyvuxStone/Model/Event/SecretConditionFriendlyMinionDestroyed.h"

nyvux::SecretConditionFriendlyMinionDestroyed::SecretConditionFriendlyMinionDestroyed(
	std::shared_ptr<nyvux::Secret> Secret,
	std::shared_ptr<nyvux::Player> Player)
		: SecretCondition(Secret),
		Player(Player)
{
}

void nyvux::SecretConditionFriendlyMinionDestroyed::OnDestroyedHook(std::shared_ptr<NyvuxStoneEvent> Event)
{
	if(!Event->CurrentPlayer)
	{
		std::shared_ptr<Minion> Minion
			= std::dynamic_pointer_cast<nyvux::Minion>(Event->TargetCard);

		if (!Minion)
			return;

		if(Player->ContainsMinionInField(Minion))
		{
			Activate();
			return;
		}
	}

	if (Event->CurrentPlayer == Player)
		Activate();
}
