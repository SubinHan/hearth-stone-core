#include "testpch.h"

#include "Helper.h"
#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandModifyRandomMinion.h"

#include "NyvuxStone/Model/Card/Secret.h"
#include "NyvuxStone/Model/Event/SecretConditionFriendlyMinionDestroyed.h"

using namespace std;

namespace nyvux
{
	class CharacterStatDecoratorModify;

	class SecretTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			Player = MakeDummyPlayerWithFakeGameMediator();
		}
		shared_ptr<Player> Player;
	};

	TEST_F(SecretTest, TestSecret)
	{
		constexpr int MODIFY_ATTACK = 2;
		constexpr int MODIFY_HEALTH = 3;

		auto Secret = Secret::CreateSecret(MockCardSpecSecret);
		auto SecretCondition = std::make_shared<SecretConditionFriendlyMinionDestroyed>(Secret, Player);
		Secret->SetSecretCondition(SecretCondition);
		Secret->AddSpellCommand(
			std::make_shared<SpellCommandModifyRandomMinion>(Player, MODIFY_ATTACK, MODIFY_HEALTH));

		Secret->AddEventListener(Player);

		Player->DrawCard();
		Player->DrawCard();
		Player->PlayMinion(0, 0);
		Player->PlayMinion(0, 0);
		auto MinionToDie = Player->GetCardInFieldAt(0);
		auto MinionToModify = Player->GetCardInFieldAt(1);

		const int BEFORE_ATTACK = MinionToModify->GetAttack();
		const int BEFORE_HEALTH = MinionToModify->GetMaxHealth();

		MinionToDie->AddEventListener(Secret);
		MinionToDie->AddEventListener(Secret->GetSecretCondition());
		MinionToDie->Destroy();


		EXPECT_EQ(BEFORE_ATTACK + MODIFY_ATTACK, MinionToModify->GetMaxHealth());
		EXPECT_EQ(BEFORE_HEALTH + MODIFY_HEALTH, MinionToModify->GetMaxHealth());
	}

}
