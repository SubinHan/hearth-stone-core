#include "pch.h"

#include "NyvuxStone/Model/Card/Character.h"

nyvux::Character::Character(const CardSpec& CardSpec)
	: Card(CardSpec),
	CharacterStat(CardSpec)
{
}

bool nyvux::Character::CanBeAttackTarget()
{
	return CharacterStat.CanBeTarget();
}

bool nyvux::Character::CanBeSpellTarget()
{
	return CharacterStat.CanBeTarget();
}

void nyvux::Character::GainDamage(const int amount)
{
	CharacterStat.Damage(amount);

	if (CharacterStat.IsDestroyed())
		Destroy();
}

void nyvux::Character::GainHeal(const int amount)
{
	CharacterStat.Heal(amount);
}

int nyvux::Character::GetMaxHealth()
{
	return CharacterStat.GetMaxHealth();
}

int nyvux::Character::GetAttack()
{
	return CharacterStat.GetAttack();
}

int nyvux::Character::GetCurrentHealth()
{
	return CharacterStat.GetCurrentHealth();
}

bool nyvux::Character::HasImmune()
{
	return CharacterStat.HasImmune();
}

bool nyvux::Character::HasFreeze()
{
	return CharacterStat.HasFreeze();
}

bool nyvux::Character::HasStealth()
{
	return CharacterStat.HasStealth();
}

bool nyvux::Character::HasWindfury()
{
	return CharacterStat.HasWindfury();
}

bool nyvux::Character::HasPoisonous()
{
	return CharacterStat.HasPoisonous();
}

bool nyvux::Character::HasLifesteal()
{
	return CharacterStat.HasLifesteal();
}

void nyvux::Character::Destroy()
{
	FireDestroyed(Event{shared_from_this()});
}
