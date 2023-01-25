#include "ICardStatDecorator.h"

nyvux::ICardStatDecorator::ICardStatDecorator(std::shared_ptr<ICardStat> Component) : Component(Component)
{
}
