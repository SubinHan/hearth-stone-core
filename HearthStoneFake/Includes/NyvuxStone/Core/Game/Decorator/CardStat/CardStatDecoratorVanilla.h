#pragma once
#include "ICardStatDecorator.h"

namespace nyvux
{
	class CardStatDecoratorVanilla : public ICardStatDecorator
	{
	public:
		CardStatDecoratorVanilla(int ManaCost);
		virtual ~CardStatDecoratorVanilla();
		int GetCurrentManaCost() override;

	private:
		int ManaCost;
	};
}
