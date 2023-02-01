#pragma once

#include "GameMediator.h"
#include "../../Model/Player/Player.h"
#include "../../View/UserInteraction.h"

#include <memory>

namespace nyvux
{
	class Game
	{
	public:
		Game();
		Game(const Game& Ref) = delete;
		Game& operator=(const Game& Ref) = delete;

	private:
		UserInteraction UserInteraction;

		std::shared_ptr<GameMediator> GameMediator;
		std::shared_ptr<Player> PlayerA;
		std::shared_ptr<Player> PlayerB;

	};
}
