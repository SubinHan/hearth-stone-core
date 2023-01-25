#pragma once

#include "Card.h"

namespace nyvux
{
	class CardFactory
	{
	public:
		static Card CreateCardById(int Id);
		static Card CreateDummyCard();
	};
}