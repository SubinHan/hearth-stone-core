#pragma once

#include "ICommand.h"
#include "NyvuxStone/Model/Player/Player.h"

#include <memory>

namespace nyvux
{
	class RemoveMinionInFieldCommand : public ICommand
	{
	public:
		RemoveMinionInFieldCommand() = delete;
		RemoveMinionInFieldCommand(std::shared_ptr<Player> Player);

		void Execute(std::shared_ptr<NyvuxStoneEvent> Event) override;
	private:
		std::shared_ptr<Player> Player;
	};
}