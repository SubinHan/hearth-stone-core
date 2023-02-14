#pragma once

#include "NyvuxStone/Model/Card/Secret.h"
#include "NyvuxStone/Core/Game/GameMediator.h"

#include <list>
#include <memory>

namespace nyvux
{
	class SecretZone
	{
	public:
		SecretZone() = default;
		static std::shared_ptr<SecretZone> CreateSecretZone();

		void RegisterSecret(std::shared_ptr<Secret> Secret, std::shared_ptr<GameMediator> GameMediator);
		bool CanAddSecret() const noexcept;
		void UnregisterSecret(std::shared_ptr<Secret> Secret, std::shared_ptr<GameMediator> GameMediator);

	public:
		static constexpr int MAX_CAPACITY = 5;

	private:
		std::list<std::shared_ptr<Secret>> SecretZoneImpl;
	};
}
