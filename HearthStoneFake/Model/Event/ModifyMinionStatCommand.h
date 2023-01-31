#pragma once

#include "../Card/Minion.h"
#include "ICommand.h"
#include "Event.h"

#include <memory>

namespace nyvux
{
	class ModifyMinionStatCommand : public ICommand
	{
	public:
		ModifyMinionStatCommand() = delete;
		ModifyMinionStatCommand(std::shared_ptr<Minion> Target, int DeltaAttack, int DeltaHealth);

		void execute(Event Event) override;

	private:
		std::shared_ptr<Minion> Target;
		int DeltaAttack;
		int DeltaHealth;
	};
}