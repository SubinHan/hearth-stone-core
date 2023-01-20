#include "Deck.h"

namespace nyvux
{
	Deck::Deck(std::vector<Card> Cards) : DeckImpl(Cards.begin(), Cards.end())
	{
	}

	Card Deck::Draw()
	{
		Card Drawn = DeckImpl.front();
		DeckImpl.pop_front();

		return Drawn;
	}

	int Deck::GetCount()
	{
		return DeckImpl.size();
	}

}

