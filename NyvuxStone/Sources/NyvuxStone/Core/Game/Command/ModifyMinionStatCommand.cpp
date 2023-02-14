#include "pch.h"

#include "NyvuxStone/Core/Game/Command/ModifyMinionStatCommand.h"

#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorModify.h"

nyvux::ModifyMinionStatCommand::ModifyMinionStatCommand(
	std::shared_ptr<Minion> Target, 
	int DeltaAttack,
	int DeltaHealth)
		: Target(Target), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

void nyvux::ModifyMinionStatCommand::Execute(std::shared_ptr<nyvux::NyvuxStoneEvent> Event)
{
	Target->Modify<CharacterStatDecoratorModify>(DeltaAttack, DeltaHealth);
}
