#include "pch.h"

#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandModifyRandomMinion.h"

#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorModify.h"

nyvux::SpellCommandModifyRandomMinion::SpellCommandModifyRandomMinion(
	std::shared_ptr<nyvux::Player> Player,
	const int DeltaAttack, 
	const int DeltaHealth)
		: Player(Player), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

void nyvux::SpellCommandModifyRandomMinion::Execute(
	std::shared_ptr<nyvux::Player> Caster,
	std::shared_ptr<Character> Target)
{
	auto Minion = Player->GetRandomMinionInField();

	Minion->Modify<CharacterStatDecoratorModify>(DeltaAttack, DeltaHealth);
}
