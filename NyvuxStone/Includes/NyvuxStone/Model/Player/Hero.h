#pragma once
#include "NyvuxStone/Model/Card/Character.h"

namespace nyvux
{
	class Hero : public Character
	{
	public:
		Hero();

		int GetCurrentArmor() const;

		bool CanAttack() override;

		void GainArmor(int Amount);
		void GainDamage(int Amount);
		void GainHeal(int Amount);

	public:
		static constexpr int DEFAULT_MAX_HEALTH = 30;

	private:
		int MaxHealth;
		int CurrentHealth;
		int CurrentArmor;
	};
}
