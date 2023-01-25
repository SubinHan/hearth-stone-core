#pragma once

#include "ICardStatDecorator.h"

#include <memory>

namespace nyvux
{
	class CardStatDecoratorModifier : public ICardStatDecorator
	{
	public:
		CardStatDecoratorModifier(std::shared_ptr<ICardStat> Component, int DeltaAttack, int DeltaHealth);
		virtual ~CardStatDecoratorModifier();
		int GetMaxHealth() override;
		int GetAttack() override;

	private:
		int DeltaAttack;
		int DeltaHealth;
	};
}
