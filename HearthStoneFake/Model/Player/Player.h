#pragma once

#include "Deck.h"
#include "Field.h"
#include "Hand.h"

#include <memory>

namespace nyvux
{
	class Player
	{
	public:
		Player(std::shared_ptr<Deck> Deck);
		static std::shared_ptr<Player> CreatePlayer(std::shared_ptr<Deck> Deck);

		void DrawCard();

	private:
		std::shared_ptr<Deck> Deck;
		std::shared_ptr<Field> Field;
		std::shared_ptr<Hand> Hand;

		
	};
}