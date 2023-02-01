#pragma once

#include <gmock/gmock.h>

#include "NyvuxStone/Model/Card/Card.h"
#include "NyvuxStone/Model/Card/CardSpecRepository.h"
#include "NyvuxStone/Model/Player/Player.h"
#include "NyvuxStone/Core/Api/HearthstoneApi.h"

#include <memory>
#include <vector>

namespace nyvux
{
	std::vector<std::shared_ptr<Card>> MakeDummyCards();
	std::shared_ptr<Player> MakeDummyPlayerWithFakeGameMediator();
	std::shared_ptr<Player> MakeDummyPlayer(std::shared_ptr<GameMediator> GameMediator);

	CardSpecRepository& MakeCardSpecRepositoryToMock();

	class MockHearthstoneApi : public HearthstoneApi
	{
	public:
		MOCK_METHOD(const std::vector<std::string>, GetAllCardList, (), (override));
		MOCK_METHOD(const CardSpec, GetCardSpecById, (const int id), (override));
		MOCK_METHOD(const std::vector<CardSpec>, GetCardSpecsByPage, (const int Page), (override));
	};

	static CardSpec MockCardSpec
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

	static constexpr int MOCK_CARD_ID = 69543;
}
