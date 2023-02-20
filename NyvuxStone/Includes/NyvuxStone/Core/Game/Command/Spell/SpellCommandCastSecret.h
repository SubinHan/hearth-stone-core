#pragma once
#include "ISpellCommand.h"
#include "NyvuxStone/Model/Secret/Secret.h"

#include <memory>

namespace nyvux
{
	class SpellCommandCastSecret : public ISpellCommand
	{
	public:
		SpellCommandCastSecret(std::shared_ptr<Secret> SecretToCast);
		virtual ~SpellCommandCastSecret() = default;

		void Execute(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target) override;

	private:
		std::shared_ptr<Secret> SecretToCast;
	};
}
