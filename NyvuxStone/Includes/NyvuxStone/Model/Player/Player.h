#pragma once

#include "Deck.h"
#include "Field.h"
#include "Hand.h"
#include "../../Core/Game/GameMediator.h"
#include "NyvuxStone/Model/Event/EventNotifier.h"

#include <memory>

#include "Hero.h"
#include "NyvuxStone/Model/Card/Spell.h"


namespace nyvux
{
	class GameMediator;

	class Player : public std::enable_shared_from_this<Player>, public EventNotifier, public EventListener
	{
	public:
		Player(std::shared_ptr<Deck> Deck, std::shared_ptr<GameMediator> GameMediator);
		static std::shared_ptr<Player> CreatePlayer(std::shared_ptr<Deck> Deck, std::shared_ptr<GameMediator> GameMediator);

		void DrawCard();
		int GetNumCardsInDeck() const;
		int GetNumCardsInHand() const;
		int GetNumPlayedInField() const;
		std::shared_ptr<Character> GetCardInFieldAt(int ZeroBasedIndex);
		void AddCardIntoHand(std::shared_ptr<Card> Card);

		void DestroyTopCardsInDeck();

		int GetCurrentHealth() const;
		int GetCurrentArmor() const;
		int GetMaxHealth() const;
		std::shared_ptr<Hero> GetHero();

		int GetCurrentMana() const;
		int GetMaxMana() const;
		int GetOverloadedMana() const;
		void IncreaseMaxMana();
		void FulfillMana();
		void OverloadMana(int Amount);
		void UnlockAllOverloadedMana();

		void PlaceCardWithoutBattlecry(int ZeroBasedHandIndex, int ZeroBasedFieldIndex);
		void RemovePlaceableInField(std::shared_ptr<Character> Card);
		void CastSpell(std::shared_ptr<Spell> Spell, std::shared_ptr<Character> Target = nullptr);
		void PlaySpell(int ZeroBasedHandIndex, std::shared_ptr<Character> Target = nullptr);

		bool CanAttack(int ZeroBasedFieldIndexOfOpponents);

	private:
		int MaxMana;
		int CurrentMana;
		int OverloadedMana;

		std::shared_ptr<Deck> Deck;
		std::shared_ptr<Field> Field;
		std::shared_ptr<Hand> Hand;
		std::shared_ptr<Hero> Hero;

		std::shared_ptr<GameMediator> GameMediator;
	};
}
