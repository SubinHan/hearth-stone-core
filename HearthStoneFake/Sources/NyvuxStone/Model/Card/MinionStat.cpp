#include "NyvuxStone/Model/Card/MinionStat.h"

#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorEmpty.h"

nyvux::MinionStat::MinionStat(const CardSpec& CardSpec)
	: Spec(CardSpec),
	Decorator(std::make_shared<MinionStatDecoratorEmpty>()),
	bIsGenerated(false),
	bCanBeTarget(true),
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

bool nyvux::MinionStat::CanBeTarget()
{
	return bCanBeTarget;
}

void nyvux::MinionStat::CorrectCurrentHealth()
{
	const int MaxHealth = GetMaxHealth();

	if (MaxHealth < CurrentHealth)
		CurrentHealth = MaxHealth;

	if (CurrentHealth < 0)
		CurrentHealth = 0;
}
