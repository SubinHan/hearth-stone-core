#pragma once

#include "Card.h"
#include "NyvuxStone/Core/Game/Command/Spell/ISpellCommand.h"

#include <vector>
#include <memory>

namespace nyvux
{
	class Spell : public Card
	{
	public:
		static std::shared_ptr<Spell> CreateSpell(const CardSpec CardSpec);

		Spell() = delete;
		Spell(const CardSpec CardSpec);
		void AddSpellCommand(std::shared_ptr<ISpellCommand> Command);
		void Cast(std::shared_ptr<Character> Target);
		bool NeedsTarget();
		void SetNeedsTarget(bool NeedsTarget);


	private:
		std::vector<std::shared_ptr<ISpellCommand>> SpellCommands;

		bool bNeedsTarget;
	};
}
