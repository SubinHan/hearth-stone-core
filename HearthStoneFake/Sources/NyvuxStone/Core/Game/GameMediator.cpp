#include "pch.h"

#include "NyvuxStone/Core/Game/GameMediator.h"

nyvux::GameMediator::GameMediator()
	: Listeners()
{
}

void nyvux::GameMediator::RegisterPlayers(std::shared_ptr<Player> PlayerA, std::shared_ptr<Player> PlayerB)
{
	this->PlayerA = PlayerA;
	this->PlayerB = PlayerB;
}

void nyvux::GameMediator::FireDrawed(std::shared_ptr<Player> Player, std::shared_ptr<nyvux::Card> Card)
{
	for (auto& Listener : Listeners)
	{
		Listener->OnDrawed(Event{ Card });
	}
}

void nyvux::GameMediator::FireSummoned(std::shared_ptr<Player> Player, std::shared_ptr<AbstractPlaceableCard> Card)
{
	AddListener(Card);
	for(auto& Listener : Listeners)
	{
		Listener->OnSummoned(Event{ Card });
	}
}

void nyvux::GameMediator::AddListener(std::shared_ptr<EventListener> Listener)
{
	Listeners.push_back(Listener);
}
