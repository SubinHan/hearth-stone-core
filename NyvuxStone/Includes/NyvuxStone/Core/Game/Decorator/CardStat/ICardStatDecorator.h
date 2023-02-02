#pragma once
#include <memory>

namespace nyvux
{
	class ICardStatDecorator
	{
	public:
		ICardStatDecorator(std::shared_ptr<ICardStatDecorator> Component);
		virtual int GetCurrentManaCost() = 0;

	protected:
		std::shared_ptr<ICardStatDecorator> Component;
	};
}
