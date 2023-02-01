#include "NyvuxStone/Model/Card/Minion.h"

nyvux::Minion::Minion(const CardSpec& CardSpec)
	: AbstractPlaceableCard(CardSpec),
	MinionStat(CardSpec)
{
}

bool nyvux::Minion::CanBeAttackTarget()
{
	return MinionStat.CanBeTarget();
}

bool nyvux::Minion::CanBeSpellTarget()
{
	return MinionStat.CanBeTarget();
}

int nyvux::Minion::GetMaxHealth()
{
	return MinionStat.GetMaxHealth();
}

int nyvux::Minion::GetAttack()
{
	return MinionStat.GetAttack();
}

int nyvux::Minion::GetCurrentHealth()
{
	return MinionStat.GetCurrentHealth();
}

bool nyvux::Minion::IsGenerated()
{
	return MinionStat.IsGenerated();
}
