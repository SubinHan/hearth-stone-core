#include "NyvuxStone/Model/Card/MinionStatDecoratorEmpty.h"

#include <memory>

using namespace std;

nyvux::MinionStatDecoratorEmpty::MinionStatDecoratorEmpty() : 
	IMinionStatDecorator(shared_ptr<IMinionStatDecorator>())
{

}

nyvux::MinionStatDecoratorEmpty::~MinionStatDecoratorEmpty()
{
}

int nyvux::MinionStatDecoratorEmpty::GetDeltaHealth()
{
	return 0;
}

int nyvux::MinionStatDecoratorEmpty::GetDeltaAttack()
{
	return 0;
}
