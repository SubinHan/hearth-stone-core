#include "pch.h"

#include "NyvuxStone/Model/Card/MinionStat.h"

nyvux::MinionStat::MinionStat()
	:bHasTaunt(false),
	bHasCharge(false),
	bHasRush(false),
	bHasDivineShield(false),
	bHasReborn(false)
{
}

void nyvux::MinionStat::GainTaunt()
{
	bHasTaunt = true;
}

void nyvux::MinionStat::Silence()
{
	bHasTaunt = false;
	bHasCharge = false;
	bHasRush = false;
	bHasDivineShield = false;
	bHasReborn = false;
}

bool nyvux::MinionStat::HasTaunt()
{
	return bHasTaunt;
}

bool nyvux::MinionStat::HasCharge()
{
	return bHasCharge;
}

bool nyvux::MinionStat::HasRush()
{
	return bHasRush;
}

bool nyvux::MinionStat::HasDivineShield()
{
	return bHasDivineShield;
}

bool nyvux::MinionStat::HasReborn()
{
	return bHasReborn;
}

void nyvux::MinionStat::RemoveDivineShield()
{
	bHasDivineShield = false;
}
