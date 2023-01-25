#pragma once

#include "CardSpec.h"
#include "CardStat.h"

#include <memory>

namespace nyvux
{
	class Card
	{
	public:
		Card(const CardSpec& Spec);
		int GetDeltaHealth();
		int GetDeltaAttack();
		int GetCurrentHealth();
		bool IsGenerated();

	private:
		const CardSpec& Spec;
		CardStat Stat;
	};
}