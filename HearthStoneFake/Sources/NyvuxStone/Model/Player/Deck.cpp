#include "NyvuxStone/Model/Player/Deck.h"

using namespace std;

namespace nyvux
{
	Deck::Deck(std::vector<shared_ptr<Card>> Cards) : DeckImpl(Cards.begin(), Cards.end())
	{
	}

	std::shared_ptr<Deck> Deck::CreateDeck(std::vector<std::shared_ptr<Card>> Cards)
	{
		return make_shared<Deck>(Cards);
	}

	shared_ptr<Card> Deck::Draw()
	{
		shared_ptr<Card> Drawn = DeckImpl.front();
		DeckImpl.pop_front();

		return Drawn;
	}

	int Deck::GetCount()
	{
		return static_cast<int>(DeckImpl.size());
	}

}

