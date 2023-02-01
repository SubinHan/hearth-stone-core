#pragma once

#include "MinionStatDecoratorBase.h"

#include <memory>

namespace nyvux
{
	class MinionStatDecoratorModify : public MinionStatDecoratorBase
	{
	public:
		MinionStatDecoratorModify(std::shared_ptr<MinionStatDecoratorBase> Component, int DeltaAttack, int DeltaHealth);
		virtual ~MinionStatDecoratorModify();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
		int DeltaAttack;
		int DeltaHealth;
	};
}
