#include "testpch.h"

#include "Helper.h"
#include "NyvuxStone/Core/Game/GameMediator.h"
#include "NyvuxStone/Model/Secret/Secret.h"
#include "NyvuxStone/Model/Player/SecretZone.h"

using namespace std;

namespace nyvux
{
	class MockGameMediator : public GameMediator
	{
	public:
		MOCK_METHOD(void, RegisterSecret, (std::shared_ptr<Secret> Secret), (override));
	};

	class MockSecret : public Secret
	{
	public:
		MockSecret() : Secret(std::vector<std::shared_ptr<ISpellCommand>>{}) {}
	};

	class SecretZoneTest : public ::testing::Test
	{
	protected:

		void SetUp() override
		{
			SecretZone = SecretZone::CreateSecretZone();
			GameMediator = make_shared<MockGameMediator>();
		}

		shared_ptr<GameMediator> GameMediator;
		shared_ptr<SecretZone> SecretZone;
	};

	TEST_F(SecretZoneTest, TestSecretZone)
	{
		shared_ptr<MockGameMediator> Mock = dynamic_pointer_cast<MockGameMediator>(GameMediator);

		EXPECT_CALL(*Mock, RegisterSecret(testing::_)).Times(5);

		for(int i = 0; i < SecretZone::MAX_CAPACITY; i++)
		{
			EXPECT_TRUE(SecretZone->CanAddSecret());
			SecretZone->RegisterSecret(std::make_shared<MockSecret>(), Mock);
		}
		EXPECT_FALSE(SecretZone->CanAddSecret());
	}

}
