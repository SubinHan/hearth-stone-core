#pragma once

#include "ICardStatDecorator.h"
#include "CardSpec.h"

namespace nyvux
{
	class CardStatDecoratorEmpty : public ICardStatDecorator
	{
	public:
		CardStatDecoratorEmpty();
		virtual ~CardStatDecoratorEmpty();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
		CardSpec Spec;
	};
}
