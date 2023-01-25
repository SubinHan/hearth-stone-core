#pragma once

#include "Card.h"

#include <vector>
#include <deque>

namespace nyvux
{
	class Deck
	{
	public:
		Deck(std::vector<Card> Cards);
		Card Draw();
		int GetCount();

	public:
		static constexpr int DEFAULT_DECK_SIZE = 30;

	private:
		std::deque<Card> DeckImpl;
	};
}