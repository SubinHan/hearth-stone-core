#include "MinionStat.h"

#include "MinionStatDecoratorEmpty.h"

nyvux::MinionStat::MinionStat(const CardSpec& CardSpec)
	: Spec(CardSpec),
	Decorator(std::make_shared<MinionStatDecoratorEmpty>()),
	bIsGenerated(false),
	CurrentHealth(Spec.Health)
{
}

int nyvux::MinionStat::GetMaxHealth()
{
	return Spec.Health + Decorator->GetDeltaHealth();
}

int nyvux::MinionStat::GetAttack()
{
	return Spec.Attack + Decorator->GetDeltaAttack();
}

int nyvux::MinionStat::GetCurrentHealth()
{
	return CurrentHealth;
}

void nyvux::MinionStat::Damage(const int Amount)
{
	CurrentHealth -= Amount;

	CorrectCurrentHealth();
}

void nyvux::MinionStat::Heal(const int Amount)
{
	CurrentHealth += Amount;

	CorrectCurrentHealth();
}

bool nyvux::MinionStat::IsGenerated()
{
	return bIsGenerated;
}

void nyvux::MinionStat::CorrectCurrentHealth()
{
	const int MaxHealth = GetMaxHealth();

	if (MaxHealth < CurrentHealth)
		CurrentHealth = MaxHealth;

	if (CurrentHealth < 0)
		CurrentHealth = 0;
}
