#include "pch.h"

#include "Helper.h"

#include "NyvuxStone/Model/Card/CardFactory.h"
#include "NyvuxStone/Model/Player/Deck.h"

using namespace std;
using namespace nyvux;
using ::testing::Return;

vector<shared_ptr<Card>> nyvux::MakeDummyCards()
{
	vector<shared_ptr<Card>> DummyCards{};
	for (int i = 0; i < Deck::DEFAULT_DECK_SIZE; i++)
	{
		DummyCards.push_back(CardFactory::CreateDummyMinion());
	}
	return DummyCards;
}

std::shared_ptr<Player> nyvux::MakeDummyPlayerWithFakeGameMediator()
{
	auto DummyCards = MakeDummyCards();
	shared_ptr<Deck> Deck = Deck::CreateDeck(DummyCards);

	return Player::CreatePlayer(Deck, make_shared<GameMediator>());
}

std::shared_ptr<Player> nyvux::MakeDummyPlayer(std::shared_ptr<GameMediator> GameMediator)
{
	auto DummyCards = MakeDummyCards();
	shared_ptr<Deck> Deck = Deck::CreateDeck(DummyCards);

	return Player::CreatePlayer(Deck, GameMediator);
}

CardSpecRepository& nyvux::MakeCardSpecRepositoryToMock()
{
	auto& Repository = CardSpecRepository::GetInstance();
	auto Mock = make_shared<MockHearthstoneApi>();
	Repository.SetHearthstoneApi(Mock);

	ON_CALL(*Mock, GetCardSpecById(69543)).WillByDefault(Return(MockCardSpec));

	return Repository;
}

