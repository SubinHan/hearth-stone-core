#include "testpch.h"

#include "Helper.h"
#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandModifyRandomMinion.h"
#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandCastSecret.h"

#include "NyvuxStone/Model/Card/Spell.h"
#include "NyvuxStone/Model/Secret/Secret.h"
#include "NyvuxStone/Model/Secret/SecretFriendlyMinionDestroyed.h"

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

		auto SecretSpell = Spell::CreateSpell(MockCardSpecSecret);
		auto SecretAction = std::vector<std::shared_ptr<ISpellCommand>>{
			std::make_shared<SpellCommandModifyRandomMinion>(
				Player, MODIFY_ATTACK, MODIFY_HEALTH)
		};
		auto Secret = std::make_shared<SecretFriendlyMinionDestroyed>(SecretAction);
		SecretSpell->AddSpellCommand(
			make_shared<SpellCommandCastSecret>(Secret));

		Player->CastSpell(SecretSpell);

		Player->DrawCard();
		Player->DrawCard();
		Player->PlayMinion(0, 0);
		Player->PlayMinion(0, 0);
		auto MinionToDie = Player->GetCardInFieldAt(0);
		auto MinionToModify = Player->GetCardInFieldAt(1);

		const int BEFORE_ATTACK = MinionToModify->GetAttack();
		const int BEFORE_HEALTH = MinionToModify->GetMaxHealth();
		
		MinionToDie->Destroy();

		EXPECT_EQ(BEFORE_ATTACK + MODIFY_ATTACK, MinionToModify->GetAttack());
		EXPECT_EQ(BEFORE_HEALTH + MODIFY_HEALTH, MinionToModify->GetMaxHealth());

		EXPECT_EQ(1, Player->GetNumPlayedInField());
	}

}
