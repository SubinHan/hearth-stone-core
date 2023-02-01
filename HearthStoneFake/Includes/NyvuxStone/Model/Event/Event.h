#pragma once

#include <memory>

namespace nyvux
{
	class Card;

	struct Event
	{
		std::shared_ptr<Card> Target;
	};
}