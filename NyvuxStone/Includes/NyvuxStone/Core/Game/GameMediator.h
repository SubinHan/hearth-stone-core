#pragma once

#include "../../Model/Player/Player.h"
#include "NyvuxStone/Model/Event/EventListener.h"
#include "NyvuxStone/Model/Event/EventNotifier.h"

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
		void RegisterCard(std::shared_ptr<Card> Card);
		void UnregisterCard(std::shared_ptr<Card> Card);

		std::shared_ptr<Player> GetOpponentPlayerOf(std::shared_ptr<Player> This);

	private:
		std::shared_ptr<Player> PlayerA;
		std::shared_ptr<Player> PlayerB;

		std::list<std::shared_ptr<EventListener>> Listeners;
		std::list<std::shared_ptr<EventNotifier>> Notifiers;
	};
}
