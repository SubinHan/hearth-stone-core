#include "MinionStatDecoratorModifier.h"

using namespace std;

nyvux::MinionStatDecoratorModifier::MinionStatDecoratorModifier(
	shared_ptr<IMinionStatDecorator> Component, int DeltaAttack, int DeltaHealth)
	: IMinionStatDecorator(Component), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

nyvux::MinionStatDecoratorModifier::~MinionStatDecoratorModifier()
{
}

int nyvux::MinionStatDecoratorModifier::GetDeltaHealth()
{
	return DeltaHealth + Component->GetDeltaHealth();
}

int nyvux::MinionStatDecoratorModifier::GetDeltaAttack()
{
	return DeltaAttack + Component->GetDeltaAttack();
}

