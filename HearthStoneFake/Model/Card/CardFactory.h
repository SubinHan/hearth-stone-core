#pragma once

#include "Card.h"
#include "Minion.h"

#include <memory>

namespace nyvux
{
	class CardFactory
	{
	public:
		static std::shared_ptr<Card> CreateCardById(const int Id);
		static std::shared_ptr<Card> CreateDummyCard();
		static std::shared_ptr<Minion> CreateMinionById(const int Id);
		static std::shared_ptr<Minion> CreateMinionBySpec(const CardSpec& Spec);
	};
}
