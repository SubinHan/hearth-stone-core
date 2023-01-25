#pragma once

#include "CardSpec.h"
#include "ICardStatDecorator.h"

#include <memory>

namespace nyvux
{
	class CardStat
	{
	public:
		CardStat(const CardSpec& CardSpec);

		void Damage(const int Amount);
		void Heal(const int Amount);

		template<class DecoratorType, class... Types>
		void Modify(Types... args);

		int GetMaxHealth();
		int GetAttack();
		int GetCurrentHealth();
		bool IsGenerated();

	private:
		void CorrectCurrentHealth();

	private:
		const CardSpec& Spec;
		std::shared_ptr<ICardStatDecorator> Decorator;

		int CurrentHealth;
		bool bIsGenerated;
	};

	template<class DecoratorType, class... Types>
	inline void CardStat::Modify(Types... Args)
	{
		const int MaxHealthPrev = GetMaxHealth();

		Decorator = make_shared<DecoratorType>(Decorator, Args...);

		const int MaxHealth = GetMaxHealth();
		const int DeltaHealth = MaxHealth - MaxHealthPrev;

		CurrentHealth += DeltaHealth;

		CorrectCurrentHealth();
	}
}