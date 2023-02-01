#pragma once

#include "CardSpec.h"
#include "../../Core/Api/HearthstoneApi.h"

#include <map>
#include <memory>

namespace nyvux
{
	class CardSpecRepository
	{
	public:
		CardSpecRepository(const CardSpecRepository& Ref) = delete;
		CardSpecRepository& operator=(const CardSpecRepository& Ref) = delete;

		static CardSpecRepository& GetInstance();
		CardSpec& GetCardSpecById(int CardId);

		void SetHearthstoneApi(std::shared_ptr<HearthstoneApi> Api);

	public:
		static const CardSpec INVALID_CARDSPEC;
		static const CardSpec DUMMY_MINION_CARDSPEC;

	private:
		CardSpecRepository();
		void InitRepository();

	private:
		std::shared_ptr<HearthstoneApi> Api;
		std::map<int, CardSpec> Repo;
	};
}