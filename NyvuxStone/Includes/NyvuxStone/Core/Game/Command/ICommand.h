#pragma once

#include "NyvuxStone/Model/Event/Event.h"

namespace nyvux
{
	class ICommand
	{
	public:
		virtual void Execute(Event Event) = 0;
	};
}
