#pragma once

#include "NyvuxStone/Model/Card/Character.h"
#include "NyvuxStone/Model/Player/Player.h"

#include <memory>

namespace nyvux
{
	class ISpellCommand
	{
	public:
		virtual void Execute(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target) = 0;
	};
}
