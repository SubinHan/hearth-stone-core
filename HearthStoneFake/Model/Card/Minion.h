#pragma once

#include "Card.h"
#include "AbstractPlaceableCard.h"
#include "MinionStat.h"

namespace nyvux
{
	class Minion : public AbstractPlaceableCard
	{
	public:
		Minion(const CardSpec& CardSpec);
		bool CanBeAttackTarget() override;
		bool CanBeSpellTarget() override;
	private:
		MinionStat MinionStat;
	};
}