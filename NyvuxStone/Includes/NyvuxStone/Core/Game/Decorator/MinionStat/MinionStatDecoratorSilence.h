#pragma once

#include "MinionStatDecoratorBase.h"

#include <memory>

namespace nyvux
{
	class MinionStatDecoratorSilence : public MinionStatDecoratorBase
	{
	public:
		MinionStatDecoratorSilence(std::shared_ptr<MinionStatDecoratorBase> Component);
		virtual ~MinionStatDecoratorSilence();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;
		bool IsTaunt() override;

	private:
	};
}
