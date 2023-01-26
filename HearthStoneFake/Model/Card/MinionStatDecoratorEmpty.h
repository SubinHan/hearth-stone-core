#pragma once

#include "IMinionStatDecorator.h"
#include "CardSpec.h"

namespace nyvux
{
	class MinionStatDecoratorEmpty : public IMinionStatDecorator
	{
	public:
		MinionStatDecoratorEmpty();
		virtual ~MinionStatDecoratorEmpty();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
		CardSpec Spec;
	};
}
