#include "testpch.h"

#include "NyvuxStone/Model/Event/EventListener.h"
#include "NyvuxStone/Core/Game/Command/ICommand.h"

using ::testing::_;
using namespace std;

namespace nyvux
{
	class MockCommand : public ICommand
	{
	public:
		MOCK_METHOD(void, Execute, (shared_ptr<NyvuxStoneEvent>), (override));
	};

	class EventListenerTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			Command = make_shared<MockCommand>();
			EmptyEvent =
				NyvuxStoneEvent::CreateNyvuxStoneEvent(nullptr, nullptr, nullptr);
		}

		shared_ptr<NyvuxStoneEvent> EmptyEvent;
		shared_ptr<MockCommand> Command;
		EventListener Listener;
	};
	TEST_F(EventListenerTest, TestOnDamaged)
	{
		EXPECT_CALL(*Command, Execute(_)).Times(3);

		Listener.AddOnDamagedCommand(Command);

		Listener.OnDamaged(EmptyEvent);
		Listener.OnDamaged(EmptyEvent);
		Listener.OnDamaged(EmptyEvent);
		Listener.OnDrawed(EmptyEvent);
		Listener.OnHealed(EmptyEvent);
	}

	TEST_F(EventListenerTest, TestOnDrawed)
	{
		EXPECT_CALL(*Command, Execute(_)).Times(3);

		Listener.AddOnDrawedCommand(Command);

		Listener.OnDrawed(EmptyEvent);
		Listener.OnDrawed(EmptyEvent);
		Listener.OnDrawed(EmptyEvent);
		Listener.OnDamaged(EmptyEvent);
		Listener.OnHealed(EmptyEvent);
	}

	TEST_F(EventListenerTest, TestOnHealed)
	{
		EXPECT_CALL(*Command, Execute(_)).Times(3);

		Listener.AddOnHealedCommand(Command);

		Listener.OnHealed(EmptyEvent);
		Listener.OnHealed(EmptyEvent);
		Listener.OnHealed(EmptyEvent);
		Listener.OnDamaged(EmptyEvent);
		Listener.OnDrawed(EmptyEvent);
	}
}
