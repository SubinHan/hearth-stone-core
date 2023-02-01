#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorModify.h"

using namespace std;

nyvux::MinionStatDecoratorModify::MinionStatDecoratorModify(
	shared_ptr<nyvux::IMinionStatDecorator> Component, int DeltaAttack, int DeltaHealth)
	: IMinionStatDecorator(Component), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
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

