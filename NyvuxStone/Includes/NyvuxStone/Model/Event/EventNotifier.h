#pragma once
#include "NyvuxStoneEvent.h"
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
		void FirePlayed(std::shared_ptr<NyvuxStoneEvent> Event);
		void FireDrawed(std::shared_ptr<NyvuxStoneEvent> Event);
		void FireCasted(std::shared_ptr<NyvuxStoneEvent> Event);
		void FireSummoned(std::shared_ptr<NyvuxStoneEvent> Event);
		void FireHealed(std::shared_ptr<NyvuxStoneEvent> Event);
		void FireUsedHeroPower(std::shared_ptr<NyvuxStoneEvent> Event);
		void FireDamaged(std::shared_ptr<NyvuxStoneEvent> Event);
		void FireDestroyed(std::shared_ptr<NyvuxStoneEvent> Event);

	private:
		std::list<std::shared_ptr<EventListener>> Listeners;
	};
}
