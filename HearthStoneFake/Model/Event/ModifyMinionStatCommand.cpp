#include "ModifyMinionStatCommand.h"

#include "../Card/MinionStatDecoratorModify.h"

nyvux::ModifyMinionStatCommand::ModifyMinionStatCommand(
	std::shared_ptr<Minion> Target, 
	int DeltaAttack,
	int DeltaHealth)
		: Target(Target), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

void nyvux::ModifyMinionStatCommand::Execute(Event Event)
{
	Target->Modify<MinionStatDecoratorModify>(DeltaAttack, DeltaHealth);
}
