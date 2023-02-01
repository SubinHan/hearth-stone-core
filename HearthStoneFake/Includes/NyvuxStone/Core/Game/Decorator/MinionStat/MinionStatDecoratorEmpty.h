#pragma once

#include "IMinionStatDecorator.h"

namespace nyvux
{
	class MinionStatDecoratorEmpty : public IMinionStatDecorator
	{
	public:
		MinionStatDecoratorEmpty();
		virtual ~MinionStatDecoratorEmpty();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;
	};
}
