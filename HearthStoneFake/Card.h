#pragma once

#include "CardSpec.h"

namespace nyvux
{
	class Card
	{
	public:
		Card(const CardSpec& Spec);
		int GetMaxHealth();
		int GetAttack();
		int GetCurrentHealth();
		bool IsGenerated();

	private:
		const CardSpec& Spec;

		int MaxHealth;
		int Attack;
		int CurrentHealth;

		bool bIsGenerated;

	};
}