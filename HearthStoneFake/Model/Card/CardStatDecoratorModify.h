#pragma once
#include "ICardStatDecorator.h"

namespace nyvux
{
	class CardStatDecoratorModify : public ICardStatDecorator
	{
	public:
		CardStatDecoratorModify(
			std::shared_ptr<ICardStatDecorator> Component,
			int DeltaManaCost
		);
		virtual ~CardStatDecoratorModify();
		int GetCurrentManaCost() override;

	private:
		int DeltaManaCost;
	};
}
