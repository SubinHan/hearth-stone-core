#pragma once

#include "NyvuxStone/Core/Game/Command/ICommand.h"
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

		void AddOnDrawedCommand(std::shared_ptr<ICommand> Command);
		void AddOnDamagedCommand(std::shared_ptr<ICommand> Command);
		void AddOnHealedCommand(std::shared_ptr<ICommand> Command);
		void AddOnSummonedCommand(std::shared_ptr<ICommand> Command);
		void AddOnPlayedCommand(std::shared_ptr<ICommand> Command);
		void AddOnUsedHeroPowerCommand(std::shared_ptr<ICommand> Command);
		void AddOnDestroyedCommand(std::shared_ptr<ICommand> Command);

		void OnDrawed(Event Event);
		void OnDamaged(Event Event);
		void OnHealed(Event Event);
		void OnSummoned(Event Event);
		void OnPlayed(Event Event);
		void OnUsedHeroPower(Event Event);
		void OnDestroyed(const Event& Event);

	private:
		std::vector<std::shared_ptr<ICommand>> OnDrawedCommands;
		std::vector<std::shared_ptr<ICommand>> OnDamagedCommands;
		std::vector<std::shared_ptr<ICommand>> OnHealedCommands;
		std::vector<std::shared_ptr<ICommand>> OnSummonedCommands;
		std::vector<std::shared_ptr<ICommand>> OnPlayedCommands;
		std::vector<std::shared_ptr<ICommand>> OnUsedHeroPowerCommands;
		std::vector<std::shared_ptr<ICommand>> OnDestroyedCommands;
	};
}