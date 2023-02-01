#pragma once

#include "IMinionStatDecorator.h"

#include <memory>

namespace nyvux
{
	class MinionStatDecoratorSilence : public IMinionStatDecorator
	{
	public:
		MinionStatDecoratorSilence(std::shared_ptr<IMinionStatDecorator> Component);
		virtual ~MinionStatDecoratorSilence();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
	};
}
