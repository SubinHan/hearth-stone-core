#pragma once

#include <map>
#include "CardSpec.h"

namespace nyvux
{
	class CardSpecRepository
	{
	public:
		CardSpecRepository(const CardSpecRepository& Ref) = delete;
		CardSpecRepository& operator=(const CardSpecRepository& Ref) = delete;
		
		CardSpecRepository();

		static CardSpecRepository& GetInstance();
		CardSpec& GetCardSpecById(int CardId);

	public:
		static const CardSpec INVALID_CARDSPEC;

	private:
		void InitRepository();

	private:
		std::map<int, CardSpec> Repo;
	};
}