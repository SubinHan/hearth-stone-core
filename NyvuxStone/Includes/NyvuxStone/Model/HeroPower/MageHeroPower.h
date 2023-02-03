#pragma once
#include "HeroPower.h"

namespace nyvux
{
	class MageHeroPower : public HeroPower
	{
	public:
		MageHeroPower();
		void UseTo(std::shared_ptr<Character> Target) noexcept(false) override;

	private:
		static constexpr int DAMAGE = 1;
		static constexpr int COST = 2;
	};
}
