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
		void AddOnSecretRevealedCommand(std::shared_ptr<ICommand> Command);
		void AddOnTurnEndedCommand(std::shared_ptr<ICommand> Command);
		void AddOnturnStartedCommand(std::shared_ptr<ICommand> Command);

		/**
		 * \brief
		 * OwnPlayer: The player has drawn.
		 * FromCard: nullptr.
		 * TargetCard: The card drawn.
		 * \param Event 
		 */
		void OnDrawed(std::shared_ptr<NyvuxStoneEvent> Event);
		/**
		 * \brief
		 * CurrentPlayer: The player that has corresponding character.
		 * FromCard: Nullable, 
		 */
		void OnDamaged(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player that has corresponding character.
		 * FromCard: .
		 * TargetCard: The character healed.
		 */
		void OnHealed(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player that has corresponding character.
		 * FromCard: .
		 * TargetCard: The character summoned.
		 */
		void OnSummoned(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player that has corresponding character.
		 * FromCard: .
		 * TargetCard: The character played.
		 */
		void OnPlayed(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player that used hero power.
		 * FromCard: .
		 * TargetCard: Hero power target.
		 */
		void OnUsedHeroPower(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player that has corresponding character.
		 * FromCard: .
		 * TargetCard: The character destroyed.
		 */
		void OnDestroyed(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player that has corresponding spell.
		 * FromCard: .
		 * TargetCard: The spell casted.
		 */
		void OnCasted(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The revealed secret owner.
		 * FromCard: nullptr.
		 * TargetCard: nullptr.
		 */
		void OnSecretRevealed(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player ended turn.
		 * FromCard: nullptr.
		 * TargetCard: nullptr.
		 */
		void OnTurnEnded(std::shared_ptr<NyvuxStoneEvent> Event);

		/**
		 * \brief
		 * CurrentPlayer: The player started turn.
		 * FromCard: nullptr.
		 * TargetCard: nullptr.
		 */
		void OnTurnStarted(std::shared_ptr<NyvuxStoneEvent> Event);

		virtual void OnEverythingHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnDrawedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnDamagedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnHealedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnSummonedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnPlayedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnUsedHeroPowerHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnDestroyedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnCastedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnSecretRevealedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnTurnEndedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}
		virtual void OnTurnStartedHook(std::shared_ptr<NyvuxStoneEvent> Event) {}

	private:
		std::vector<std::shared_ptr<ICommand>> OnDrawedCommands;
		std::vector<std::shared_ptr<ICommand>> OnDamagedCommands;
		std::vector<std::shared_ptr<ICommand>> OnHealedCommands;
		std::vector<std::shared_ptr<ICommand>> OnSummonedCommands;
		std::vector<std::shared_ptr<ICommand>> OnPlayedCommands;
		std::vector<std::shared_ptr<ICommand>> OnUsedHeroPowerCommands;
		std::vector<std::shared_ptr<ICommand>> OnDestroyedCommands;
		std::vector<std::shared_ptr<ICommand>> OnCastedCommands;
		std::vector<std::shared_ptr<ICommand>> OnSecretRevealedCommands;
		std::vector<std::shared_ptr<ICommand>> OnTurnEndedCommands;
		std::vector<std::shared_ptr<ICommand>> OnTurnStartedCommands;
	};
}