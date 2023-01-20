#include "CardSpecRepository.h"
#include "CardSpecRepository.h"
#include "HearthstoneApi.h"

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
			"",
			"",
			-1,
			std::vector<int>{},
			std::vector<int>{}
		};

	CardSpecRepository::CardSpecRepository() : Repo()
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

		CardSpec Spec = HearthstoneApi::GetCardSpecById(CardId);
		Repo[CardId] = Spec;

		return Repo[CardId];
	}

	void CardSpecRepository::InitRepository()
	{

	}
}


