#pragma once

#include "../Card/Card.h"

#include <vector>
#include <deque>
#include <memory>

namespace nyvux
{
	class Deck
	{
	public:
		Deck(std::vector<std::shared_ptr<Card>> Cards);
		std::shared_ptr<Card> Draw();
		int GetCount();

	public:
		static constexpr int DEFAULT_DECK_SIZE = 30;

	private:
		std::deque<std::shared_ptr<Card>> DeckImpl;
	};
}