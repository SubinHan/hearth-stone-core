#include "NyvuxStone/Core/Game/Decorator/CardStat/ICardStatDecorator.h"

nyvux::ICardStatDecorator::ICardStatDecorator(std::shared_ptr<ICardStatDecorator> Component)
	: Component(Component)
{
}
