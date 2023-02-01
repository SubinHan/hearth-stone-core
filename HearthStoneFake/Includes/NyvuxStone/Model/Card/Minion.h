#pragma once

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

		int GetMaxHealth();
		int GetAttack();
		int GetCurrentHealth();
		bool IsGenerated();

		template<class DecoratorType, class... Types>
		void Modify(Types... Args);
		bool IsTaunt();

	private:
		MinionStat MinionStat;
	};

	template <class DecoratorType, class ... Types>
	void Minion::Modify(Types... Args)
	{
		MinionStat.Modify<DecoratorType>(Args...);
	}
}
