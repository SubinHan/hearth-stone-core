#include "NyvuxStone/Core/Game/Decorator/CardStat/CardStatDecoratorModify.h"

#include <algorithm>

nyvux::CardStatDecoratorModify::CardStatDecoratorModify(
	std::shared_ptr<ICardStatDecorator> Component,
	int DeltaManaCost)
	: ICardStatDecorator(Component),
	DeltaManaCost(DeltaManaCost)
{
}

nyvux::CardStatDecoratorModify::~CardStatDecoratorModify()
{
}

int nyvux::CardStatDecoratorModify::GetCurrentManaCost()
{
	int CurrentManaCost = DeltaManaCost + Component->GetCurrentManaCost();

	return std::max(0, CurrentManaCost);
}