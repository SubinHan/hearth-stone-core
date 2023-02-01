#include "NyvuxStone/Core/Game/Decorator/MinionStat/IMinionStatDecorator.h"

nyvux::IMinionStatDecorator::IMinionStatDecorator(std::shared_ptr<IMinionStatDecorator> Component)
	: Component(Component)
{
}
