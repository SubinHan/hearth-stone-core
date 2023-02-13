#pragma once

#include "ISpellCommand.h"
#include "NyvuxStone/Model/Card/Character.h"

namespace nyvux
{
	class SpellCommandDealDamage : public ISpellCommand
	{
	public:
		SpellCommandDealDamage(const int Amount);
		virtual ~SpellCommandDealDamage() = default;
		void Execute(std::shared_ptr<Character> Target) override;

	private:
		int Amount;
	};
}
