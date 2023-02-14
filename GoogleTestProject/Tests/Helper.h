#pragma once

#include <gmock/gmock.h>

#include "NyvuxStone/Model/Card/Card.h"
#include "NyvuxStone/Model/Card/CardSpecRepository.h"
#include "NyvuxStone/Model/Player/Player.h"
#include "NyvuxStone/Core/Api/HearthstoneApi.h"
#include "NyvuxStone/Core/Game/GameMediator.h"

#include <memory>
#include <vector>

namespace nyvux
{
	class MockCharacter;

	std::vector<std::shared_ptr<Card>> MakeDummyCards();
	std::shared_ptr<Player> MakeDummyPlayerWithFakeGameMediator();
	std::shared_ptr<Player> MakeDummyPlayer(std::shared_ptr<GameMediator> GameMediator);

	CardSpecRepository& MakeCardSpecRepositoryToMock();
	std::shared_ptr<MockCharacter> MakeMockCharacter();
	std::shared_ptr<Spell> MakeNonTargetSpell();
	std::shared_ptr<Spell> MakeTargetSpell();

	class MockHearthstoneApi : public HearthstoneApi
	{
	public:
		MOCK_METHOD(const std::vector<std::string>, GetAllCardList, (), (override));
		MOCK_METHOD(const CardSpec, GetCardSpecById, (const int id), (override));
		MOCK_METHOD(const std::vector<CardSpec>, GetCardSpecsByPage, (const int Page), (override));
	};

	class MockCharacter : public Character
	{
	public:
		MockCharacter();

		MOCK_METHOD(void, GainDamage, (const int amount), (override));
		MOCK_METHOD(void, GainHeal, (const int amount), (override));
		MOCK_METHOD(bool, CanAttack, (), (override));
	};

	static const CardSpec MockCardSpecMinion =
	{
		69543,
		true,
		"69543-chillwind-yeti",
		12,
		std::vector<int>(),
		-1,
		4,
		1637,
		1,
		5,
		4,
		4,
		"Chillwind Yeti",
		"",
		69543,
		std::vector<int>(),
		std::vector<int>()
	};

	static const CardSpec MockCardSpecSpellNeedsTarget =
	{
		64631,
		true,
		"64631-aimed-shot",
		3,
		std::vector<int>(),
		-1,
		5,
		1578,
		1,
		-1,
		-1,
		3,
		"Aimed Shot",
		"Deal 3 damage. Your next Hero Power deals 2 more damage.",
		64631,
		std::vector<int>{},
		std::vector<int>{}
	};

	static const CardSpec MockCardSpecSpellNonTarget =
	{
		63211,
		true,
		"63211-altar-of-fire",
		9,
		std::vector<int>(),
		2,
		5,
		1525,
		4,
		-1,
		-1,
		1,
		"Altar of Fire",
		"Destroy the top 3 cards of each deck.",
		63211,
		std::vector<int>{},
		std::vector<int>{}
	};

	static const CardSpec MockCardSpecSecret =
	{
		69704,
		true,
		"69704-avenge",
		5,
		std::vector<int>(),
		5,
		5,
		1637,
		1,
		-1,
		-1,
		1,
		"Avenge",
		"<b>Secret:</b> When one of your minions dies, give a random friendly minion +3/+2.",
		69704,
		std::vector<int>{},
		std::vector<int>{5}
	};

	static constexpr int MOCK_CARD_ID = 69543;
}
