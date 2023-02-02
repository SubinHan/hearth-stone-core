#pragma once

#include "../Model/Player/Deck.h"

namespace nyvux
{
	class UserInteraction
	{
	public:
		std::shared_ptr<Deck> ReadDeckPlayerA();
		std::shared_ptr<Deck> ReadDeckPlayerB();
	};
}