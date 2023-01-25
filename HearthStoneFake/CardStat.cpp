#include "CardStat.h"

#include "CardStatDecoratorEmpty.h"

nyvux::CardStat::CardStat(const CardSpec& CardSpec)
	: Spec(CardSpec),
	Decorator(std::make_shared<CardStatDecoratorEmpty>()),
	bIsGenerated(false),
	CurrentHealth(Spec.Health)
{
}

int nyvux::CardStat::GetMaxHealth()
{
	return Spec.Health + Decorator->GetDeltaHealth();
}

int nyvux::CardStat::GetAttack()
{
	return Spec.Attack + Decorator->GetDeltaAttack();
}

int nyvux::CardStat::GetCurrentHealth()
{
	return CurrentHealth;
}

void nyvux::CardStat::Damage(const int Amount)
{
	CurrentHealth -= Amount;

	CorrectCurrentHealth();
}

void nyvux::CardStat::Heal(const int Amount)
{
	CurrentHealth += Amount;

	CorrectCurrentHealth();
}

bool nyvux::CardStat::IsGenerated()
{
	return bIsGenerated;
}

void nyvux::CardStat::CorrectCurrentHealth()
{
	const int MaxHealth = GetMaxHealth();

	if (MaxHealth < CurrentHealth)
		CurrentHealth = MaxHealth;

	if (CurrentHealth < 0)
		CurrentHealth = 0;
}
