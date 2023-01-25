#pragma once

#include "ICardStat.h"
#include "CardSpec.h"

namespace nyvux
{
	class CardStatVanilla : public ICardStat
	{
	public:
		CardStatVanilla(CardSpec Spec);
		virtual ~CardStatVanilla();
		int GetMaxHealth() override;
		int GetAttack() override;

	private:
		CardSpec Spec;
	};
}
