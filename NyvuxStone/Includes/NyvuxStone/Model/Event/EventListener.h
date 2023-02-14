#pragma once

#include "NyvuxStone/Core/Game/Command/ICommand.h"
#include "NyvuxStoneEvent.h"

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
		void AddOnCastedCommand(std::shared_ptr<ICommand> Command);

		void OnDrawed(std::shared_ptr<NyvuxStoneEvent> Event);
		void OnDamaged(std::shared_ptr<NyvuxStoneEvent> Event);
		void OnHealed(std::shared_ptr<NyvuxStoneEvent> Event);
		void OnSummoned(std::shared_ptr<NyvuxStoneEvent> Event);
		void OnPlayed(std::shared_ptr<NyvuxStoneEvent> Event);
		void OnUsedHeroPower(std::shared_ptr<NyvuxStoneEvent> Event);
		void OnDestroyed(std::shared_ptr<NyvuxStoneEvent> Event);
		void OnCasted(std::shared_ptr<NyvuxStoneEvent> Event);

	private:
		std::vector<std::shared_ptr<ICommand>> OnDrawedCommands;
		std::vector<std::shared_ptr<ICommand>> OnDamagedCommands;
		std::vector<std::shared_ptr<ICommand>> OnHealedCommands;
		std::vector<std::shared_ptr<ICommand>> OnSummonedCommands;
		std::vector<std::shared_ptr<ICommand>> OnPlayedCommands;
		std::vector<std::shared_ptr<ICommand>> OnUsedHeroPowerCommands;
		std::vector<std::shared_ptr<ICommand>> OnDestroyedCommands;
		std::vector<std::shared_ptr<ICommand>> OnCastedCommands;
	};
}