#include "CardStat.h"

#include "CardStatDecoratorVanilla.h"

nyvux::CardStat::CardStat(const CardSpec& Spec)
	: Spec(Spec),
	Decorator(std::make_shared<CardStatDecoratorVanilla>(Spec.ManaCost)),
	bIsGenerated(false),
	CurrentManaCost(Spec.ManaCost)
{
}

int nyvux::CardStat::GetManaCost()
{
	return Decorator->GetCurrentManaCost();
}

bool nyvux::CardStat::IsGenerated()
{
	return bIsGenerated;
}