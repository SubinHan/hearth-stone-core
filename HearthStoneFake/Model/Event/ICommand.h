#pragma once

#include "Event.h"

namespace nyvux
{
	class ICommand
	{
	public:
		virtual void Execute(Event Event) = 0;
	};
}