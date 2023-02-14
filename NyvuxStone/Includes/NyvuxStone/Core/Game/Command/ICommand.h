#pragma once

#include "NyvuxStone/Model/Event/NyvuxStoneEvent.h"

#include <memory>

namespace nyvux
{
	class ICommand
	{
	public:
		virtual void Execute(std::shared_ptr<NyvuxStoneEvent> Event) = 0;
	};
}
