#include "CardStatDecoratorSilence.h"

nyvux::CardStatDecoratorSilence::CardStatDecoratorSilence(std::shared_ptr<ICardStatDecorator> Component)
	: ICardStatDecorator(Component)
{
}

nyvux::CardStatDecoratorSilence::~CardStatDecoratorSilence()
{
}

int nyvux::CardStatDecoratorSilence::GetDeltaHealth()
{
	return 0;
}

int nyvux::CardStatDecoratorSilence::GetDeltaAttack()
{
	return 0;
}
