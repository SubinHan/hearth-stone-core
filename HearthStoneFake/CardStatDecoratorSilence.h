#pragma once

#include "ICardStatDecorator.h"

#include <memory>

namespace nyvux
{
	class CardStatDecoratorSilence : public ICardStatDecorator
	{
	public:
		CardStatDecoratorSilence(std::shared_ptr<ICardStatDecorator> Component);
		virtual ~CardStatDecoratorSilence();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
	};
}
