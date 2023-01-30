#pragma once

#include "../../Model/Player/Player.h"

#include <memory>

namespace nyvux
{
	class GameMediator
	{
	public:
		GameMediator() = default;
		GameMediator(GameMediator& Ref) = delete;
		GameMediator& operator=(GameMediator& Ref) = delete;

		void RegisterPlayers(std::shared_ptr<Player> PlayerA, std::shared_ptr<Player> PlayerB);

	private:
		std::shared_ptr<Player> PlayerA;
		std::shared_ptr<Player> PlayerB;
	};
}
