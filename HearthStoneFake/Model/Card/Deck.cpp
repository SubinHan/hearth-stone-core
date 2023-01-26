#include "Deck.h"

using namespace std;

namespace nyvux
{
	Deck::Deck(std::vector<shared_ptr<Card>> Cards) : DeckImpl(Cards.begin(), Cards.end())
	{
	}

	shared_ptr<Card> Deck::Draw()
	{
		shared_ptr<Card> Drawn = DeckImpl.front();
		DeckImpl.pop_front();

		return Drawn;
	}

	int Deck::GetCount()
	{
		return DeckImpl.size();
	}

}

