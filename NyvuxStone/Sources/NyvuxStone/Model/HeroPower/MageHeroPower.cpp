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
	auto Minion = dynamic_pointer_cast<nyvux::Minion>(Target);

	if (!Minion)
		throw HeroPowerException("The target is not a minion");

	if (!(Minion->CanBeSpellTarget()))
		throw HeroPowerException("The target is immune");

	Minion->GainDamage(DAMAGE);
}