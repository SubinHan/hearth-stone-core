#pragma once

#include "IMinionStatDecorator.h"

#include <memory>

namespace nyvux
{
	class MinionStatDecoratorModify : public IMinionStatDecorator
	{
	public:
		MinionStatDecoratorModify(std::shared_ptr<IMinionStatDecorator> Component, int DeltaAttack, int DeltaHealth);
		virtual ~MinionStatDecoratorModify();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
		int DeltaAttack;
		int DeltaHealth;
	};
}
