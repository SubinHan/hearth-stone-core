#pragma once

#include "Spell.h"

#include <memory>

namespace nyvux
{
	class SecretCondition;

	class Secret : public Spell, public std::enable_shared_from_this<Secret>
	{
	public:
		Secret() = delete;

		static std::shared_ptr<Secret> CreateSecret(const CardSpec CardSpec);
		Secret(const CardSpec CardSpec);

		void Cast(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target) override;
		void Activate();
		void SetSecretCondition(std::shared_ptr<SecretCondition> SecretCondition);
		std::shared_ptr<SecretCondition> GetSecretCondition();

	private:
		std::shared_ptr<Player> Caster;
		std::shared_ptr<SecretCondition> SecretCondition;
	};
}
