#pragma once
#include "ISecret.h"
#include "NyvuxStone/Model/Player/Player.h"

namespace nyvux
{
	class IGameMediator
	{
	public:
		virtual ~IGameMediator() = default;

		virtual void RegisterPlayers(std::shared_ptr<Player> PlayerA, 
			std::shared_ptr<Player> PlayerB) = 0;
		virtual void RegisterSecret(std::shared_ptr<ISecret> Secret) = 0;
		virtual void UnregisterSecret(std::shared_ptr<ISecret> Secret) = 0;

		virtual std::shared_ptr<Player> GetOpponentPlayerOf(std::shared_ptr<Player> This) = 0;

	};
}
