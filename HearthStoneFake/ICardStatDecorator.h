#pragma once

#include "ICardStat.h"

#include <memory>

namespace nyvux
{
	class ICardStatDecorator : public ICardStat
	{
	public:
		ICardStatDecorator(std::shared_ptr<ICardStat> Component);

	protected:
		std::shared_ptr<ICardStat> Component;
	};
}
