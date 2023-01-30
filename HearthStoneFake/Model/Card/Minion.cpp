#include "Minion.h"

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
