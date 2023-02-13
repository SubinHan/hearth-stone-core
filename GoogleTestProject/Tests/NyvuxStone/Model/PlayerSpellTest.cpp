#include "testpch.h"

#include "NyvuxStone/Core/Game/GameMediator.h"
#include "NyvuxStone/Model/Card/Spell.h"

#include "Helper.h"
#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandDealDamage.h"
#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandDestroyCardsTopDeck.h"
#include "NyvuxStone/Model/Player/PlayerException.h"

using namespace std;

namespace nyvux
{
	class PlayerGameMediatorTest : public ::testing::Test
	{

	protected:
		void SetUp()
		{
			GameMediator = make_shared<nyvux::GameMediator>();
			PlayerA = MakeDummyPlayer(GameMediator);
			PlayerB = MakeDummyPlayer(GameMediator);

			GameMediator->RegisterPlayers(PlayerA, PlayerB);
		}

		shared_ptr<GameMediator> GameMediator;
		shared_ptr<Player> PlayerA;
		shared_ptr<Player> PlayerB;
	};

	TEST_F(PlayerGameMediatorTest, TestNonTargetSpell)
	{
		constexpr int DESTROY_AMOUNT = 3;

		std::shared_ptr<Spell> NonTargetSpell = std::make_shared<Spell>(MockCardSpecSpellNonTarget);
		NonTargetSpell->AddSpellCommand(
			std::make_shared<SpellCommandDestroyCardsTopDeck>(PlayerA, DESTROY_AMOUNT)
		);
		NonTargetSpell->AddSpellCommand(
			std::make_shared<SpellCommandDestroyCardsTopDeck>(PlayerB, DESTROY_AMOUNT)
		);

		PlayerB->DrawCard();
		PlayerA->AddCardIntoHand(NonTargetSpell);

		int NumCardsOfDeckPlayerABefore = PlayerA->GetNumCardsInDeck();
		int NumCardsOfDeckPlayerBBefore = PlayerB->GetNumCardsInDeck();
		int NumCardsOfHandPlayerABefore = PlayerA->GetNumCardsInHand();

		PlayerA->IncreaseMaxMana();
		PlayerA->FulfillMana();

		PlayerA->PlaySpell(0);

		const int EXPECTED_NUM_CARDS_OF_DECK_PLAYER_A =
			NumCardsOfDeckPlayerABefore - DESTROY_AMOUNT;
		const int EXPECTED_NUM_CARDS_OF_DECK_PLAYER_B =
			NumCardsOfDeckPlayerBBefore - DESTROY_AMOUNT;
		const int EXPECTED_NUM_CARDS_HAND_OF_PLAYER_A =
			NumCardsOfHandPlayerABefore - 1;

		EXPECT_EQ(EXPECTED_NUM_CARDS_OF_DECK_PLAYER_A, PlayerA->GetNumCardsInDeck());
		EXPECT_EQ(EXPECTED_NUM_CARDS_OF_DECK_PLAYER_B, PlayerB->GetNumCardsInDeck());
		EXPECT_EQ(EXPECTED_NUM_CARDS_HAND_OF_PLAYER_A, PlayerA->GetNumCardsInHand());
	}

	TEST_F(PlayerGameMediatorTest, TestNonTargetSpellException)
	{
		constexpr int DESTROY_AMOUNT = 3;

		std::shared_ptr<Spell> NonTargetSpell = std::make_shared<Spell>(MockCardSpecSpellNonTarget);
		NonTargetSpell->AddSpellCommand(
			std::make_shared<SpellCommandDestroyCardsTopDeck>(PlayerA, DESTROY_AMOUNT)
		);
		NonTargetSpell->AddSpellCommand(
			std::make_shared<SpellCommandDestroyCardsTopDeck>(PlayerB, DESTROY_AMOUNT)
		);

		PlayerA->AddCardIntoHand(NonTargetSpell);

		EXPECT_THROW({
			PlayerA->PlaySpell(0);
		}, PlayerException);
	}

	TEST_F(PlayerGameMediatorTest, TestSpellWithTarget)
	{
		constexpr int DAMAGE_AMOUNT = 3;

		std::shared_ptr<Spell> SpellWithTarget = std::make_shared<Spell>(MockCardSpecSpellNeedsTarget);
		SpellWithTarget->AddSpellCommand(
			std::make_shared<SpellCommandDealDamage>(DAMAGE_AMOUNT)
		);

		PlayerA->IncreaseMaxMana();
		PlayerA->IncreaseMaxMana();
		PlayerA->IncreaseMaxMana();
		PlayerA->FulfillMana();

		PlayerA->AddCardIntoHand(SpellWithTarget);

		int NumCardsOfHandPlayerABefore = PlayerA->GetNumCardsInHand();
		const int HeroHealthBefore = PlayerA->GetCurrentHealth();
		PlayerA->PlaySpell(0, PlayerA->GetHero());


		const int EXPECTED_HERO_HEALTH = HeroHealthBefore - DAMAGE_AMOUNT;
		const int EXPECTED_NUM_CARDS_HAND_OF_PLAYER_A =
			NumCardsOfHandPlayerABefore - 1;

		EXPECT_EQ(EXPECTED_HERO_HEALTH, PlayerA->GetCurrentHealth());
		EXPECT_EQ(EXPECTED_NUM_CARDS_HAND_OF_PLAYER_A, PlayerA->GetNumCardsInHand());
	}

	TEST_F(PlayerGameMediatorTest, TestSpellWithTargetException)
	{
		constexpr int DAMAGE_AMOUNT = 3;

		std::shared_ptr<Spell> SpellWithTarget = std::make_shared<Spell>(MockCardSpecSpellNeedsTarget);
		SpellWithTarget->SetNeedsTarget(true);

		SpellWithTarget->AddSpellCommand(
			std::make_shared<SpellCommandDealDamage>(DAMAGE_AMOUNT)
		);

		PlayerA->IncreaseMaxMana();
		PlayerA->FulfillMana();

		PlayerA->AddCardIntoHand(SpellWithTarget);

		EXPECT_THROW({
			PlayerA->PlaySpell(0);
			}, PlayerException);
	}

}