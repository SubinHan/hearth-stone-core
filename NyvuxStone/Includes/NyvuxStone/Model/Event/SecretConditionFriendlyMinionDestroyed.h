#pragma once

#include "SecretCondition.h"

#include <memory>

namespace nyvux
{
	class SecretConditionFriendlyMinionDestroyed : public SecretCondition
	{
	public:
		SecretConditionFriendlyMinionDestroyed(
			std::shared_ptr<nyvux::Secret> Secret,
			std::shared_ptr<Player> Player);
		void OnDestroyedHook(std::shared_ptr<NyvuxStoneEvent> Event) override;

	private:
		std::shared_ptr<Player> Player;
	};
}
