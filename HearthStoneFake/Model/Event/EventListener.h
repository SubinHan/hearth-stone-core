#pragma once

#include "ICommand.h"
#include "Event.h"

#include <vector>
#include <memory>

namespace nyvux
{
	class EventListener
	{
	public:
		EventListener() = default;
		virtual ~EventListener();
		void OnDrawed(Event Event);
		void OnDamaged(Event Event);
		void OnHealed(Event Event);
		void OnSummoned(Event Event);

		void AddOnDrawedCommand(std::shared_ptr<ICommand> Command);
		void AddOnDamagedCommand(std::shared_ptr<ICommand> Command);
		void AddOnHealedCommand(std::shared_ptr<ICommand> Command);
		void AddOnSummonedCommand(std::shared_ptr<ICommand> Command);

	private:
		std::vector<std::shared_ptr<ICommand>> OnDrawedCommands;
		std::vector<std::shared_ptr<ICommand>> OnDamagedCommands;
		std::vector<std::shared_ptr<ICommand>> OnHealedCommands;
		std::vector<std::shared_ptr<ICommand>> OnSummonedCommands;
	};
}