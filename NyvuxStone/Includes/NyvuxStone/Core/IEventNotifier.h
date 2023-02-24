#pragma once
#include "IEventListener.h"

#include <memory>

namespace nyvux
{
	class IEventNotifier
	{
	public:
		virtual ~IEventNotifier() = default;
		void AddEventListener(std::shared_ptr<IEventListener> Listener);
		void RemoveEventListener(std::shared_ptr<IEventListener> Listener);
	};
}
