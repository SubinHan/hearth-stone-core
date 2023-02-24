#pragma once
#include "Game/Command/Spell/ISpellCommand.h"

#include <memory>

namespace nyvux
{
	class ISpell
	{
	public:
		virtual ~ISpell();

		virtual void AddSpellCommand(std::shared_ptr<ISpellCommand> Command) = 0;
		virtual void Cast(std::shared_ptr<Character> Target) = 0;
		virtual bool NeedsTarget() = 0;
	};
}
