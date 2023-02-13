#include "pch.h"

#include "NyvuxStone/Model/Player/Hero.h"
#include "NyvuxStone/Model/Card/CardSpecRepository.h"

std::shared_ptr<nyvux::Hero> nyvux::Hero::CreateHero()
{
	return std::make_shared<Hero>();
}

nyvux::Hero::Hero()
	: Character(CardSpecRepository::HERO_CARDSPEC),
	MaxHealth(DEFAULT_MAX_HEALTH),
	CurrentHealth(MaxHealth),
	CurrentArmor(0)
{
}

int nyvux::Hero::GetCurrentArmor() const
{
	return CurrentArmor;
}

bool nyvux::Hero::CanAttack()
{
	// TODO: Implement this.
	return true;
}

void nyvux::Hero::GainArmor(int Amount)
{
	CurrentArmor += Amount;
}

void nyvux::Hero::GainDamage(int Amount)
{
	CurrentArmor -= Amount;

	if(CurrentArmor < 0)
	{
		Character::GainDamage(-CurrentArmor);
		CurrentArmor = 0;
	}
	else
	{
		Character::GainDamage(0);
	}
}

void nyvux::Hero::GainHeal(int Amount)
{
	Character::GainHeal(Amount);
}