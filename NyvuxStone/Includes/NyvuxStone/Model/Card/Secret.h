#pragma once

#include "Spell.h"

namespace nyvux
{
	class Secret : public Spell
	{
	public:
		Secret() = delete;
		Secret(const CardSpec CardSpec);
	};
}
