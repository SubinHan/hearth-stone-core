#include "NyvuxStone/Model/Card/IMinionStatDecorator.h"

nyvux::IMinionStatDecorator::IMinionStatDecorator(std::shared_ptr<IMinionStatDecorator> Component)
	: Component(Component)
{
}
