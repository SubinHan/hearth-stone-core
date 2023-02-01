#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorSilence.h"

nyvux::MinionStatDecoratorSilence::MinionStatDecoratorSilence(std::shared_ptr<nyvux::MinionStatDecoratorBase> Component)
	: MinionStatDecoratorBase(Component)
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

bool nyvux::MinionStatDecoratorSilence::IsTaunt()
{
	return false;
}

