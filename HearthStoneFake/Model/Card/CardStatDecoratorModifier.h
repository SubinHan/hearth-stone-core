#pragma once

#include "ICardStatDecorator.h"

#include <memory>

namespace nyvux
{
	class CardStatDecoratorModifier : public ICardStatDecorator
	{
	public:
		CardStatDecoratorModifier(std::shared_ptr<ICardStatDecorator> Component, int DeltaAttack, int DeltaHealth);
		virtual ~CardStatDecoratorModifier();
		int GetDeltaHealth() override;
		int GetDeltaAttack() override;

	private:
		int DeltaAttack;
		int DeltaHealth;
	};
}
