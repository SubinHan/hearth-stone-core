#include "pch.h"

#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorModify.h"

using namespace std;

nyvux::MinionStatDecoratorModify::MinionStatDecoratorModify(
	shared_ptr<nyvux::MinionStatDecoratorBase> Component, int DeltaAttack, int DeltaHealth)
	: MinionStatDecoratorBase(Component), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

nyvux::MinionStatDecoratorModify::~MinionStatDecoratorModify()
{
}

int nyvux::MinionStatDecoratorModify::GetDeltaHealth()
{
	return DeltaHealth + Component->GetDeltaHealth();
}

int nyvux::MinionStatDecoratorModify::GetDeltaAttack()
{
	return DeltaAttack + Component->GetDeltaAttack();
}

