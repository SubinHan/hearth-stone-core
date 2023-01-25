#include "CardStatDecoratorModifier.h"

using namespace std;

nyvux::CardStatDecoratorModifier::CardStatDecoratorModifier(
	shared_ptr<ICardStatDecorator> Component, int DeltaAttack, int DeltaHealth)
	: ICardStatDecorator(Component), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

nyvux::CardStatDecoratorModifier::~CardStatDecoratorModifier()
{
}

int nyvux::CardStatDecoratorModifier::GetDeltaHealth()
{
	return DeltaHealth + Component->GetDeltaHealth();
}

int nyvux::CardStatDecoratorModifier::GetDeltaAttack()
{
	return DeltaAttack + Component->GetDeltaAttack();
}

