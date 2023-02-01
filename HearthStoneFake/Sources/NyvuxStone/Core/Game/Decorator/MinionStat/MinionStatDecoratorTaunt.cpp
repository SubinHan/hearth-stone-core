#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorTaunt.h"

nyvux::MinionStatDecoratorTaunt::MinionStatDecoratorTaunt(std::shared_ptr<MinionStatDecoratorBase> Component)
	: MinionStatDecoratorBase(Component)
{
}

nyvux::MinionStatDecoratorTaunt::~MinionStatDecoratorTaunt()
{
}

bool nyvux::MinionStatDecoratorTaunt::IsTaunt()
{
	return true;
}
