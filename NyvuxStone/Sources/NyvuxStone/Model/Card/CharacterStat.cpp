#include "pch.h"

#include "NyvuxStone/Model/Card/CharacterStat.h"

nyvux::CharacterStat::CharacterStat(const CardSpec CardSpec)
	: Spec(CardSpec),
	Decorator(std::make_shared<CharacterStatDecoratorBase>(nullptr)),
	bCanBeTarget(true),
	bHasImmune(false),
	bHasFreeze(false),
	bHasStealth(false),
	bHasWindfury(false),
	bHasPoisonous(false),
	bHasLifesteal(false),
	CurrentHealth(Spec.Health)
{
}

int nyvux::CharacterStat::GetMaxHealth() const
{
	return Spec.Health + Decorator->GetDeltaHealth();
}

int nyvux::CharacterStat::GetAttack() const
{
	return Spec.Attack + Decorator->GetDeltaAttack();
}

int nyvux::CharacterStat::GetCurrentHealth() const
{
	return CurrentHealth;
}

void nyvux::CharacterStat::Damage(const int Amount)
{
	CurrentHealth -= Amount;

	CorrectCurrentHealth();
}

void nyvux::CharacterStat::Heal(const int Amount)
{
	CurrentHealth += Amount;

	CorrectCurrentHealth();
}

bool nyvux::CharacterStat::CanBeTarget() const
{
	return bCanBeTarget;
}

bool nyvux::CharacterStat::HasImmune() const
{
	return bHasImmune;
}

bool nyvux::CharacterStat::HasFreeze() const
{
	return bHasFreeze;
}

bool nyvux::CharacterStat::HasStealth() const
{
	return bHasStealth;
}

bool nyvux::CharacterStat::HasWindfury() const
{
	return bHasWindfury;
}

bool nyvux::CharacterStat::HasPoisonous() const
{
	return bHasPoisonous;
}

bool nyvux::CharacterStat::HasLifesteal() const
{
	return bHasLifesteal;
}

bool nyvux::CharacterStat::IsDestroyed()
{
	return CurrentHealth <= 0;
}

void nyvux::CharacterStat::CorrectCurrentHealth()
{
	const int MaxHealth = GetMaxHealth();

	if (MaxHealth < CurrentHealth)
		CurrentHealth = MaxHealth;

	if (CurrentHealth < 0)
		CurrentHealth = 0;
}
