#pragma once

namespace nyvux
{
	class EventNotifier
	{
		void FirePlayed();
		void FireDrawed();
		void FireSummoned();
		void FireCardDamaged();
		void FireHealed();
		void FireUsedHeroPower();
		void FIreHeroDamaged();

	};
}