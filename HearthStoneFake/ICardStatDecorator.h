#pragma once

#include <memory>

namespace nyvux
{
	class ICardStatDecorator
	{
	public:
		ICardStatDecorator(std::shared_ptr<ICardStatDecorator> Component);
		virtual int GetDeltaHealth() = 0;
		virtual int GetDeltaAttack() = 0;

	protected:
		std::shared_ptr<ICardStatDecorator> Component;
	};
}
