#include "CardSpecRepository.h"
#include "CardSpecRepository.h"
#include "../../Core/Api/HearthstoneApi.h"

namespace nyvux
{
	const CardSpec CardSpecRepository::INVALID_CARDSPEC =
		CardSpec{
			-1,
			false,
			"",
			-1,
			std::vector<int>{},
			-1,
			-1,
			-1,
			-1,
			-1,
			-1,
			-1,
			"",
			"",
			-1,
			std::vector<int>{},
			std::vector<int>{}
		};

	const CardSpec CardSpecRepository::DUMMY_MINION_CARDSPEC =
		CardSpec{
			1,
			false,
			"1-dummy-slug",
			1,
			std::vector<int>{},
			1,
			1,
			1,
			1,
			1,
			0,
			0,
			"Dummy Card",
			"It's a dummy card for tests",
			1,
			std::vector<int>{},
			std::vector<int>{}
	};

	CardSpecRepository::CardSpecRepository() : Repo(), Api(std::make_shared<HearthstoneApi>())
	{
		InitRepository();
	}

	CardSpecRepository& CardSpecRepository::GetInstance()
	{
		static CardSpecRepository Instance;
		return Instance;
	}

	CardSpec& CardSpecRepository::GetCardSpecById(int CardId)
	{
		if (Repo.find(CardId) != Repo.end())
			return Repo[CardId];

		CardSpec Spec = Api->GetCardSpecById(CardId);
		Repo[CardId] = Spec;

		return Repo[CardId];
	}

	void CardSpecRepository::SetHearthstoneApi(std::shared_ptr<HearthstoneApi> Api)
	{
		this->Api = Api;
	}

	void CardSpecRepository::InitRepository()
	{

	}
}


