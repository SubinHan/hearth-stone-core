#pragma once
#include "ICommand.h"
#include "NyvuxStone/Core/Game/GameMediator.h"

#include <memory>

namespace nyvux
{
	class UnregisterCardCommand : public ICommand
	{
	public:
		UnregisterCardCommand() = delete;
		UnregisterCardCommand(std::shared_ptr<GameMediator> GameMediator);
		virtual ~UnregisterCardCommand() = default;

		void Execute(std::shared_ptr<NyvuxStoneEvent> Event) override;

	private:
		std::shared_ptr<GameMediator> GameMediator;
	};
}
