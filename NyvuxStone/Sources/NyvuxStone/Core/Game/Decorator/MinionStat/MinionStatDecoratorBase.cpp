#include "pch.h"

#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorBase.h"

nyvux::MinionStatDecoratorBase::MinionStatDecoratorBase()
	: MinionStatDecoratorBase(nullptr)
{
}

nyvux::MinionStatDecoratorBase::MinionStatDecoratorBase(std::shared_ptr<MinionStatDecoratorBase> Component)
	: Component(Component)
{
}

int nyvux::MinionStatDecoratorBase::GetDeltaHealth()
{
	if (!Component)
		return 0;

	return Component->GetDeltaHealth();
}

int nyvux::MinionStatDecoratorBase::GetDeltaAttack()
{
	if (!Component)
		return 0;

	return Component->GetDeltaAttack();
}

bool nyvux::MinionStatDecoratorBase::IsTaunt()
{
	if (!Component)
		return false;

	return Component->IsTaunt();
}
