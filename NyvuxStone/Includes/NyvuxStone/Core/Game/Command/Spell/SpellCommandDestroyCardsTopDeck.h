#pragma once

#include "ISpellCommand.h"
#include "NyvuxStone/Model/Player/Player.h"

namespace nyvux
{
	class SpellCommandDestroyCardsTopDeck : public ISpellCommand
	{
	public:
		SpellCommandDestroyCardsTopDeck(std::shared_ptr<Player> Target, const int Amount);
		virtual ~SpellCommandDestroyCardsTopDeck() = default;
		void Execute(std::shared_ptr<Character> Target) override;

	private:
		std::shared_ptr<Player> Target;
		int Amount;
	};
}
