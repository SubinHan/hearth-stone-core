#pragma once

#include "ICommand.h"
#include "NyvuxStone/Model/Player/Player.h"

#include <memory>

namespace nyvux
{
	class RemovePlaceableInFieldCommand : public ICommand
	{
	public:
		RemovePlaceableInFieldCommand() = delete;
		RemovePlaceableInFieldCommand(std::shared_ptr<Player> Player);

		void Execute(Event Event) override;
	private:
		std::shared_ptr<Player> Player;
	};
}