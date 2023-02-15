#pragma once
#include "ISpellCommand.h"

namespace nyvux
{
	class SpellCommandModifyRandomMinion : public ISpellCommand
	{
	public:
		SpellCommandModifyRandomMinion(
			std::shared_ptr<Player> Player, const int DeltaAttack, const int DeltaHealth);
		virtual ~SpellCommandModifyRandomMinion() = default;
		void Execute(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target) override;

	private:
		std::shared_ptr<Player> Player;
		int DeltaAttack;
		int DeltaHealth;
	};
}
