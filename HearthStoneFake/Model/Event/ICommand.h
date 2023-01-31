#pragma once

#include "Event.h"

namespace nyvux
{
	class ICommand
	{
	public:
		virtual void execute(Event Event) = 0;
	};
}