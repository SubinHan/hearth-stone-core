#pragma once

#include "IMinionStatDecorator.h"

#include <memory>

namespace nyvux
{
	class MinionStatDecoratorModifier : public IMinionStatDecorator
	{
	public:
		MinionStatDecoratorModifier(std::shared_ptr<IMinionStatDecorator> Component, int DeltaAttack, int DeltaHealth);
		virtual ~MinionStatDecoratorModifier();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
		int DeltaAttack;
		int DeltaHealth;
	};
}
