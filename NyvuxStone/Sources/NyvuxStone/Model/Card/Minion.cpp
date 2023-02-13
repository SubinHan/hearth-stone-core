#include "pch.h"

#include "NyvuxStone/Model/Card/Minion.h"
#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorSilence.h"

std::shared_ptr<nyvux::Minion> nyvux::Minion::CreateMinion(const CardSpec CardSpec)
{
	return std::make_shared<Minion>(CardSpec);
}

nyvux::Minion::Minion(const CardSpec CardSpec)
	: Character(CardSpec)
{
}

void nyvux::Minion::GainDamage(const int amount)
{
	if(MinionStat.HasDivineShield())
	{
		MinionStat.RemoveDivineShield();
		return;
	}

	Character::GainDamage(amount);
}

void nyvux::Minion::GainHeal(const int amount)
{
	Character::GainHeal(amount);
}

void nyvux::Minion::GainTaunt()
{
	MinionStat.GainTaunt();
}

void nyvux::Minion::Silence()
{
	MinionStat.Silence();
	Modify<CharacterStatDecoratorSilence>();
}

bool nyvux::Minion::CanAttack()
{
	// TODO: Implment this.
	return true;
}

bool nyvux::Minion::HasTaunt()
{
	return MinionStat.HasTaunt();
}

bool nyvux::Minion::HasCharge()
{
	return MinionStat.HasCharge();
}

bool nyvux::Minion::HasRush()
{
	return MinionStat.HasRush();
}

bool nyvux::Minion::HasDivineShield()
{
	return MinionStat.HasDivineShield();
}

bool nyvux::Minion::HasReborn()
{
	return MinionStat.HasReborn();
}
