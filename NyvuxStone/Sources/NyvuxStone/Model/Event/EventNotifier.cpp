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

void nyvux::EventNotifier::FirePlayed(Event Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnPlayed(Event);
	}
}

void nyvux::EventNotifier::FireDrawed(Event Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnDrawed(Event);
	}
}

void nyvux::EventNotifier::FireSummoned(Event Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnSummoned(Event);
	}
}

void nyvux::EventNotifier::FireHealed(Event Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnHealed(Event);
	}
}

void nyvux::EventNotifier::FireUsedHeroPower(Event Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnUsedHeroPower(Event);
	}
}

void nyvux::EventNotifier::FireDamaged(Event Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnDamaged(Event);
	}
}

void nyvux::EventNotifier::FireDestroyed(Event Event)
{
	for (auto EventListener : Listeners)
	{
		EventListener->OnDestroyed(Event);
	}
}
