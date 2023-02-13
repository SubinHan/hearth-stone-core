#pragma once

#include "Card.h"
#include "Minion.h"
#include "Spell.h"

#include <memory>


namespace nyvux
{
	class CardFactory
	{
	public:
		static std::shared_ptr<Card> CreateCardById(const int Id);
		static std::shared_ptr<Minion> CreateDummyMinion();
		static std::shared_ptr<Minion> CreateMinionById(const int Id);
		static std::shared_ptr<Minion> CreateMinionBySpec(const CardSpec Spec);
		static std::shared_ptr<Spell> CreateSpellBySpec(const CardSpec Spec);
	};
}
