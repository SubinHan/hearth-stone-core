#pragma once
#include "NyvuxStone/Model/Event/NyvuxStoneEvent.h"

namespace nyvux
{
	class IEventListener
	{
	public:
		virtual ~IEventListener() = default;

		/**
		 * \brief
		 * OwnPlayer: The player has drawn.
		 * FromCard: nullptr.
		 * TargetCard: The card drawn.
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
	};
}
