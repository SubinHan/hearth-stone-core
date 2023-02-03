#pragma once

#include <memory>

namespace nyvux
{
	class CharacterStatDecoratorBase
	{
	public:
		CharacterStatDecoratorBase();
		virtual ~CharacterStatDecoratorBase() = default;;

		CharacterStatDecoratorBase(std::shared_ptr<CharacterStatDecoratorBase> Component);
		virtual int GetDeltaHealth();
		virtual int GetDeltaAttack();

	protected:
		std::shared_ptr<CharacterStatDecoratorBase> Component;
	};
}
