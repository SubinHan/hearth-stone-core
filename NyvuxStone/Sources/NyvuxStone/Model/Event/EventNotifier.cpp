#include "pch.h"

#include "NyvuxStone/Model/Event/EventNotifier.h"

void nyvux::EventNotifier::AddEventListener(std::shared_ptr<EventListener> Listener)
{
	Listeners.push_back(Listener);
}

void nyvux::EventNotifier::RemoveEventListener(std::shared_ptr<EventListener> Listener)
{
	Listeners.remove(Listener);
}

void nyvux::EventNotifier::FirePlayed(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnPlayed(Event);
	}
}

void nyvux::EventNotifier::FireDrawed(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnDrawed(Event);
	}
}

void nyvux::EventNotifier::FireCasted(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnCasted(Event);
	}
}

void nyvux::EventNotifier::FireSummoned(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnSummoned(Event);
	}
}

void nyvux::EventNotifier::FireHealed(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnHealed(Event);
	}
}

void nyvux::EventNotifier::FireUsedHeroPower(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnUsedHeroPower(Event);
	}
}

void nyvux::EventNotifier::FireDamaged(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnDamaged(Event);
	}
}

void nyvux::EventNotifier::FireDestroyed(std::shared_ptr<NyvuxStoneEvent> Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnDestroyed(Event);
	}
}
