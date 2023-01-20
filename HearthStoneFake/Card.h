#pragma once

#include "CardSpec.h"

namespace nyvux
{
	class Card
	{
	public:
		Card(CardSpec& Spec);
		int GetMaxHealth();
		int GetAttack();
		int GetCurrentHealth();
		bool IsGenerated();

	private:
		CardSpec& Spec;

		int MaxHealth;
		int Attack;
		int CurrentHealth;

		bool bIsGenerated;

	};
}