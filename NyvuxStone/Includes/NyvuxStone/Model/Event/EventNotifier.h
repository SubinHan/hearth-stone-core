#pragma once
#include "Event.h"
#include "EventListener.h"

#include <memory>
#include <list>

namespace nyvux
{
	class EventNotifier
	{
	public:
		EventNotifier() = default;
		void AddEventListener(std::shared_ptr<EventListener> Listener);
		void RemoveEventListener(std::shared_ptr<EventListener> Listener);

	protected:
		void FirePlayed(Event Event);
		void FireDrawed(Event Event);
		void FireCasted(Event Event);
		void FireSummoned(Event Event);
		void FireHealed(Event Event);
		void FireUsedHeroPower(Event Event);
		void FireDamaged(Event Event);
		void FireDestroyed(Event Event);

	private:
		std::list<std::shared_ptr<EventListener>> Listeners;
	};
}
