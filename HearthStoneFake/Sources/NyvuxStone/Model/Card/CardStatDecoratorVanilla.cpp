#include "NyvuxStone/Model/Card/CardStatDecoratorVanilla.h"

nyvux::CardStatDecoratorVanilla::CardStatDecoratorVanilla(int ManaCost)
	: ICardStatDecorator(nullptr),
	ManaCost(ManaCost)
{
}

nyvux::CardStatDecoratorVanilla::~CardStatDecoratorVanilla()
{
}

int nyvux::CardStatDecoratorVanilla::GetCurrentManaCost()
{
	return ManaCost;
}
