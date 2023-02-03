#pragma once

#include "CharacterStatDecoratorBase.h"

#include <memory>

namespace nyvux
{
	class CharacterStatDecoratorModify : public CharacterStatDecoratorBase
	{
	public:
		CharacterStatDecoratorModify(std::shared_ptr<CharacterStatDecoratorBase> Component, int DeltaAttack, int DeltaHealth);
		~CharacterStatDecoratorModify() override = default;
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
		int DeltaAttack;
		int DeltaHealth;
	};
}
