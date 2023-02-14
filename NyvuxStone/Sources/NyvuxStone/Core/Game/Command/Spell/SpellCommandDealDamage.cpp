#include "pch.h"

#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandDealDamage.h"

nyvux::SpellCommandDealDamage::SpellCommandDealDamage(const int Amount)
	: Amount(Amount)
{
}

void nyvux::SpellCommandDealDamage::Execute(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target)
{
	Target->GainDamage(Amount);
}
