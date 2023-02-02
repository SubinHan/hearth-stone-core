#pragma once

#include "CardSpec.h"
#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorBase.h"

#include <memory>


namespace nyvux
{
	class MinionStat
	{
	public:
		MinionStat(const CardSpec& CardSpec);

		void Damage(const int Amount);
		void Heal(const int Amount);

		template<class DecoratorType, class... Types>
		void Modify(Types... Args);

		int GetMaxHealth();
		int GetAttack();
		int GetCurrentHealth();
		bool IsGenerated();
		bool IsTaunt();
		bool CanBeTarget();

	private:
		void CorrectCurrentHealth();

	private:
		const CardSpec& Spec;
		std::shared_ptr<MinionStatDecoratorBase> Decorator;

		int CurrentHealth;
		bool bIsGenerated;
		bool bCanBeTarget;
	};

	template<class DecoratorType, class... Types>
	inline void MinionStat::Modify(Types... Args)
	{
		const int MaxHealthPrev = GetMaxHealth();

		Decorator = std::make_shared<DecoratorType>(Decorator, Args...);

		const int MaxHealth = GetMaxHealth();
		const int DeltaHealth = MaxHealth - MaxHealthPrev;

		CurrentHealth += DeltaHealth;

		CorrectCurrentHealth();
	}
}
