#include "CardStatDecoratorModifier.h"

using namespace std;

nyvux::CardStatDecoratorModifier::CardStatDecoratorModifier(
	shared_ptr<ICardStat> Component, int DeltaAttack, int DeltaHealth)
	: ICardStatDecorator(Component), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

nyvux::CardStatDecoratorModifier::~CardStatDecoratorModifier()
{
}

int nyvux::CardStatDecoratorModifier::GetMaxHealth()
{
	return DeltaHealth + Component->GetMaxHealth();
}

int nyvux::CardStatDecoratorModifier::GetAttack()
{
	return DeltaAttack + Component->GetAttack();
}

