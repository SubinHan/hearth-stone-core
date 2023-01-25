#include "CardStatDecoratorEmpty.h"

#include <memory>

using namespace std;

nyvux::CardStatDecoratorEmpty::CardStatDecoratorEmpty() : 
	ICardStatDecorator(shared_ptr<ICardStatDecorator>())
{

}

nyvux::CardStatDecoratorEmpty::~CardStatDecoratorEmpty()
{
}

int nyvux::CardStatDecoratorEmpty::GetDeltaHealth()
{
	return 0;
}

int nyvux::CardStatDecoratorEmpty::GetDeltaAttack()
{
	return 0;
}
