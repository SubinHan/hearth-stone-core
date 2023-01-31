#pragma once

#include "../../Model/Player/Player.h"
#include "../../Model/Event/ICommand.h"

#include <memory>
#include <list>


namespace nyvux
{
	class Player;

	class GameMediator
	{
	public:
		GameMediator();
		GameMediator(GameMediator& Ref) = delete;
		GameMediator& operator=(GameMediator& Ref) = delete;
		~GameMediator() = default;

		void RegisterPlayers(std::shared_ptr<Player> PlayerA, std::shared_ptr<Player> PlayerB);
		void FireDrawed(std::shared_ptr<Player> Player, std::shared_ptr<Card> Card);
		void FireSummoned(std::shared_ptr<Player> Player, std::shared_ptr<AbstractPlaceableCard> Card);

	private:
		void AddListener(std::shared_ptr<EventListener> Listener);

	private:
		std::shared_ptr<Player> PlayerA;
		std::shared_ptr<Player> PlayerB;

		std::list<std::shared_ptr<EventListener>> Listeners;
	};
}
