#pragma once

namespace nyvux
{
	class ICardStat
	{
	public:
		virtual ~ICardStat() = default;
		virtual int GetMaxHealth() = 0;
		virtual int GetAttack() = 0;
	};
}

