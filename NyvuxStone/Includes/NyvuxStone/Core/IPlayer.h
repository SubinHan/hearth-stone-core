#pragma once
#include "IDeck.h"
#include "IField.h"
#include "IHand.h"
#include "IHero.h"
#include "ISpell.h"
#include "ISecretZone.h"

namespace nyvux
{
	class IPlayer
	{
	public:
		virtual ~IPlayer() = default;

		virtual std::shared_ptr<IGameMediator> GetGameMediator() const = 0;
		virtual std::shared_ptr<IDeck> GetDeck() const = 0;
		virtual std::shared_ptr<IField> GetField() const = 0;
		virtual std::shared_ptr<IHand> GetHand() const = 0;
		virtual std::shared_ptr<IHero> GetHero() const = 0;
		virtual std::shared_ptr<ISecretZone> GetSecretZone() const = 0;

		virtual void DrawCard() = 0;

		virtual int GetCurrentMana() const = 0;
		virtual int GetMaxMana() const = 0;
		virtual int GetOverloadedMana() const = 0;
		virtual void IncreaseMaxMana() = 0;
		virtual void FufillMana() = 0;
		virtual void OverloadMana(int Amount) = 0;
		virtual void UnlockAllOverloadedMana() = 0;

		virtual void PlayCard(int ZeroBasedHandIndex,
			int ZeroBasedFieldIndex,
			std::shared_ptr<ICharacter> Target = nullptr) = 0;

		virtual void CastSpell(std::shared_ptr<ISpell> Spell,
			std::shared_ptr<ICharacter> Target = nullptr) = 0;
	};
}
