#include "testpch.h"

#include "Helper.h"

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
		}
		
	};

	TEST_F(SecretTest, TestSecret)
	{
		//auto Secret = Secret::CreateSecret(MockCardSpecSecret);
		//auto SecretCondition = std::make_shared<SecretConditionFriendlyMinionDestroyed>(Player);
		//Secret->SetSecretCondition(SecretCondition);

	}

}
