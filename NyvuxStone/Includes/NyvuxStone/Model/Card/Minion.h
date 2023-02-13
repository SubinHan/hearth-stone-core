#pragma once

#include "Character.h"
#include "MinionStat.h"

#include <memory>

namespace nyvux
{
	class Minion : public Character
	{
	public:
		static std::shared_ptr<Minion> CreateMinion(const CardSpec CardSpec);

		Minion(const CardSpec CardSpec);

		void GainDamage(const int amount) override;
		void GainHeal(const int amount) override;

		void GainTaunt();
		void Silence();

		bool CanAttack() override;

		bool HasTaunt();
		bool HasCharge();
		bool HasRush();
		bool HasDivineShield();
		bool HasReborn();

	private:
		MinionStat MinionStat;
	};
}
