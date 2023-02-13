#pragma once
#include "Card.h"

namespace nyvux
{
	class Spell : public Card
	{
	public:
		Spell() = delete;
		Spell(const CardSpec& CardSpec);
	};
}
