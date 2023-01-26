#include "MinionStatDecoratorSilence.h"

nyvux::MinionStatDecoratorSilence::MinionStatDecoratorSilence(std::shared_ptr<IMinionStatDecorator> Component)
	: IMinionStatDecorator(Component)
{
}

nyvux::MinionStatDecoratorSilence::~MinionStatDecoratorSilence()
{
}

int nyvux::MinionStatDecoratorSilence::GetDeltaHealth()
{
	return 0;
}

int nyvux::MinionStatDecoratorSilence::GetDeltaAttack()
{
	return 0;
}
