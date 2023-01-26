#pragma once

#include "Card.h"
#include "IPlaceable.h"
#include "MinionStat.h"

namespace nyvux
{
	class Minion : public Card, public IPlaceable
	{
	public:
		Minion(const CardSpec& CardSpec);
		bool CanBeAttackTarget() override;
		bool CanBeSpellTarget() override;
	private:
		MinionStat MinionStat;
	};
}