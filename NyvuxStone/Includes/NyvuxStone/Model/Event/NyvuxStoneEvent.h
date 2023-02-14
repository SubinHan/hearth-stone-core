#pragma once

#include <memory>

namespace nyvux
{
	class Card;
	class Player;

	struct NyvuxStoneEvent
	{
		static std::shared_ptr<NyvuxStoneEvent> CreateNyvuxStoneEvent(
			std::shared_ptr<Player> CurrentPlayer,
			std::shared_ptr<Card> FromCard,
			std::shared_ptr<Card> TargetCard
			)
		{
			return std::make_shared<NyvuxStoneEvent>(CurrentPlayer, FromCard, TargetCard);
		}

		std::shared_ptr<Player> CurrentPlayer;
		std::shared_ptr<Card> FromCard;
		std::shared_ptr<Card> TargetCard;
	};
}
