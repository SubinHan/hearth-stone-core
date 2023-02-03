#pragma once

#include "CharacterStatDecoratorBase.h"

#include <memory>

namespace nyvux
{
	class CharacterStatDecoratorSilence : public CharacterStatDecoratorBase
	{
	public:
		CharacterStatDecoratorSilence(std::shared_ptr<CharacterStatDecoratorBase> Component);
		~CharacterStatDecoratorSilence() override = default;
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
	};
}
