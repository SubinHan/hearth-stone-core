#include "pch.h"

#include "NyvuxStone/Core/Game/Decorator/CardStat/CardStatDecoratorVanilla.h"

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
