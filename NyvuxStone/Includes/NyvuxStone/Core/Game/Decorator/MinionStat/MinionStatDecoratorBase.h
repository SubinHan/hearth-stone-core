#pragma once

#include <memory>

namespace nyvux
{
	class MinionStatDecoratorBase
	{
	public:
		MinionStatDecoratorBase();
		MinionStatDecoratorBase(std::shared_ptr<MinionStatDecoratorBase> Component);
		virtual int GetDeltaHealth();
		virtual int GetDeltaAttack();
		virtual bool IsTaunt();

	protected:
		std::shared_ptr<MinionStatDecoratorBase> Component;
	};
}
