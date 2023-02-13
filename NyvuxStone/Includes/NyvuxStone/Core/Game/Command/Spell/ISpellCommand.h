#pragma once

#include "NyvuxStone/Model/Card/Character.h"

#include <memory>

namespace nyvux
{
	class ISpellCommand
	{
	public:
		virtual void Execute(std::shared_ptr<Character> Target) = 0;
	};
}
