#include "pch.h"

#include "NyvuxStone/Model/Secret/SecretFriendlyMinionDestroyed.h"

nyvux::SecretFriendlyMinionDestroyed::SecretFriendlyMinionDestroyed(
	std::vector<std::shared_ptr<ISpellCommand>> Actions)
		: Secret(Actions)
{
}

void nyvux::SecretFriendlyMinionDestroyed::OnDestroyedHook(std::shared_ptr<NyvuxStoneEvent> Event)
{
	if(Event->Owner == Caster)
	{
		Activate();
	}
}
