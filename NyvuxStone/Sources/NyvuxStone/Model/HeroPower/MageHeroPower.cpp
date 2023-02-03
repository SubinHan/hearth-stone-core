#include "pch.h"

#include "NyvuxStone/Model/HeroPower/MageHeroPower.h"

#include "NyvuxStone/Model/Card/Minion.h"

using namespace std;

nyvux::MageHeroPower::MageHeroPower()
	: HeroPower(true, COST)
{
}

void nyvux::MageHeroPower::UseTo(std::shared_ptr<Character> Target) noexcept(false)
{
	if (Target->HasImmune())
		throw HeroPowerException("The target is immune");

	Target->GainDamage(DAMAGE);
}