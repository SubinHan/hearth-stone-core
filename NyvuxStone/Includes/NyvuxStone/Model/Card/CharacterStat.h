#pragma once

#include "CardSpec.h"
#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorBase.h"

#include <memory>

namespace nyvux
{
	class CharacterStat
	{
	public:
		CharacterStat(const CardSpec& CardSpec);

		void Damage(const int Amount);
		void Heal(const int Amount);

		int GetMaxHealth() const;
		int GetAttack() const;
		int GetCurrentHealth() const;
		bool CanBeTarget() const;
		bool HasImmune() const;
		bool HasFreeze() const;
		bool HasStealth() const;
		bool HasWindfury() const;
		bool HasPoisonous() const;
		bool HasLifesteal() const;

		template<class DecoratorType, class... Types>
		void Modify(Types... Args);
		bool IsDestroyed();

	private:
		void CorrectCurrentHealth();

	private:
		const CardSpec& Spec;
		std::shared_ptr<CharacterStatDecoratorBase> Decorator;

		int CurrentHealth;
		bool bCanBeTarget;
		bool bHasImmune;
		bool bHasFreeze;
		bool bHasStealth;
		bool bHasWindfury;
		bool bHasPoisonous;
		bool bHasLifesteal;
	};

	template<class DecoratorType, class... Types>
	void CharacterStat::Modify(Types... Args)
	{
		const int MaxHealthPrev = GetMaxHealth();

		Decorator = std::make_shared<DecoratorType>(Decorator, Args...);

		const int MaxHealth = GetMaxHealth();
		const int DeltaHealth = MaxHealth - MaxHealthPrev;

		CurrentHealth += DeltaHealth;

		CorrectCurrentHealth();
	}
}
