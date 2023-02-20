#include "pch.h"

#include "NyvuxStone/Model/Secret/Secret.h"

nyvux::Secret::Secret(std::vector<std::shared_ptr<ISpellCommand>> Actions)
	: Actions(Actions)
{
}

void nyvux::Secret::SetCaster(std::shared_ptr<Player> Caster)
{
	this->Caster = Caster;
}

void nyvux::Secret::Activate()
{
	for(auto Action : Actions)
	{
		Action->Execute(Caster, nullptr);
	}

	auto Event =
		NyvuxStoneEvent::CreateNyvuxStoneEvent(Caster, nullptr, nullptr);

	FireSecretRevealed(Event);
}
