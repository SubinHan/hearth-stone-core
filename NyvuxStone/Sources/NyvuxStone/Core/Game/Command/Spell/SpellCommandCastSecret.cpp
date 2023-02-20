#include "pch.h"

#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandCastSecret.h"

nyvux::SpellCommandCastSecret::SpellCommandCastSecret(std::shared_ptr<Secret> SecretToCast)
	: SecretToCast(SecretToCast)
{
}

void nyvux::SpellCommandCastSecret::Execute(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target)
{
	if (!Caster->CanAddSecret())
		return;

	SecretToCast->SetCaster(Caster);
	Caster->AddSecret(SecretToCast);
}
