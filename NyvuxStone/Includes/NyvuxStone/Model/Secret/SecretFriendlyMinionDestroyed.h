#pragma once
#include "Secret.h"

namespace nyvux
{
	class SecretFriendlyMinionDestroyed : public Secret
	{
	public:
		SecretFriendlyMinionDestroyed(
			std::vector<std::shared_ptr<ISpellCommand>> Actions);
		virtual ~SecretFriendlyMinionDestroyed() = default;
		
		void OnDestroyedHook(std::shared_ptr<NyvuxStoneEvent> Event) override;
	};
}
