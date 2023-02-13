#include "testpch.h"

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

	ON_CALL(*Mock, GetCardSpecById(69543)).WillByDefault(Return(MockCardSpecMinion));

	return Repository;
}

std::shared_ptr<MockCharacter> nyvux::MakeMockCharacter()
{
	return std::make_shared<MockCharacter>();
}

std::shared_ptr<Spell> nyvux::MakeNonTargetSpell()
{
	return Spell::CreateSpell(MockCardSpecSpellNonTarget);
}

std::shared_ptr<Spell> nyvux::MakeTargetSpell()
{
	return Spell::CreateSpell(MockCardSpecSpellNeedsTarget);
}

MockCharacter::MockCharacter()
	: Character(MockCardSpecMinion)
{
}

