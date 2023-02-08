#include "pch.h"

#include "NyvuxStone/Core/Game/GameMediator.h"
#include "NyvuxStone/Core/Game/Command/UnregisterCardCommand.h"

std::shared_ptr<nyvux::GameMediator> nyvux::GameMediator::CreateGameMediator()
{
	auto GameMediator = std::make_shared<nyvux::GameMediator>();
	GameMediator->AddOnDestroyedCommand(std::make_shared<UnregisterCardCommand>(GameMediator));
	GameMediator->Listeners.push_back(GameMediator);
	return GameMediator;
}

nyvux::GameMediator::GameMediator()
	: Listeners()
{
}

void nyvux::GameMediator::RegisterPlayers(std::shared_ptr<Player> PlayerA, std::shared_ptr<Player> PlayerB)
{
	this->PlayerA = PlayerA;
	this->PlayerB = PlayerB;

	Notifiers.push_back(PlayerA);
	Notifiers.push_back(PlayerB);
	Listeners.push_back(PlayerA);
	Listeners.push_back(PlayerB);

	PlayerA->AddEventListener(PlayerB);
	PlayerB->AddEventListener(PlayerA);
}

void nyvux::GameMediator::RegisterCard(std::shared_ptr<Card> Card)
{
	for (auto Notifier : Notifiers)
	{
		Notifier->AddEventListener(Card);
	}

	for (auto Listener : Listeners)
	{
		Card->AddEventListener(Listener);
	}

	Listeners.push_back(Card);
	Notifiers.push_back(Card);
}

void nyvux::GameMediator::UnregisterCard(std::shared_ptr<Card> Card)
{
	for (auto Notifier : Notifiers)
	{
		Notifier->RemoveEventListener(Card);
	}

	Listeners.remove(Card);
	Notifiers.remove(Card);
}

std::shared_ptr<nyvux::Player> nyvux::GameMediator::GetOpponentPlayerOf(std::shared_ptr<Player> This)
{
	return This == PlayerA ? PlayerB : PlayerA;
}
