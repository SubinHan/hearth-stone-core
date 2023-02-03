#pragma once

namespace nyvux
{
	class MinionStat
	{
	public:
		MinionStat();

		void GainTaunt();
		void Silence();

		bool HasTaunt();
		bool HasCharge();
		bool HasRush();
		bool HasDivineShield();
		bool HasReborn();
		void RemoveDivineShield();

	private:
		bool bHasTaunt;
		bool bHasCharge;
		bool bHasRush;
		bool bHasDivineShield;
		bool bHasReborn;
	};

}
