#include "pch.h"

#include "NyvuxStone/Model/Event/EventListener.h"

nyvux::EventListener::~EventListener()
{
}

void nyvux::EventListener::AddOnPlayedCommand(std::shared_ptr<ICommand> Command)
{
	OnPlayedCommands.push_back(Command);
}

void nyvux::EventListener::AddOnUsedHeroPowerCommand(std::shared_ptr<ICommand> Command)
{
	OnUsedHeroPowerCommands.push_back(Command);
}

void nyvux::EventListener::AddOnDestroyedCommand(std::shared_ptr<ICommand> Command)
{
	OnDestroyedCommands.push_back(Command);
}

void nyvux::EventListener::AddOnCastedCommand(std::shared_ptr<ICommand> Command)
{
	OnCastedCommands.push_back(Command);
}

void nyvux::EventListener::AddOnDrawedCommand(std::shared_ptr<nyvux::ICommand> Command)
{
	OnDrawedCommands.push_back(Command);
}

void nyvux::EventListener::AddOnDamagedCommand(std::shared_ptr<nyvux::ICommand> Command)
{
	OnDamagedCommands.push_back(Command);
}

void nyvux::EventListener::AddOnHealedCommand(std::shared_ptr<nyvux::ICommand> Command)
{
	OnHealedCommands.push_back(Command);
}

void nyvux::EventListener::AddOnSummonedCommand(std::shared_ptr<ICommand> Command)
{
	OnSummonedCommands.push_back(Command);
}


void nyvux::EventListener::OnDrawed(Event Event)
{
	for (auto Command : OnDrawedCommands)
	{
		Command->Execute(Event);
	}
}

void nyvux::EventListener::OnDamaged(Event Event)
{
	for (auto Command : OnDamagedCommands)
	{
		Command->Execute(Event);
	}
}

void nyvux::EventListener::OnHealed(Event Event)
{
	for (auto Command : OnHealedCommands)
	{
		Command->Execute(Event);
	}
}

void nyvux::EventListener::OnSummoned(Event Event)
{
	for (auto Command : OnSummonedCommands)
	{
		Command->Execute(Event);
	}
}

void nyvux::EventListener::OnPlayed(Event Event)
{
	for (auto Command : OnPlayedCommands)
	{
		Command->Execute(Event);
	}
}

void nyvux::EventListener::OnUsedHeroPower(Event Event)
{
	for (auto Command : OnUsedHeroPowerCommands)
	{
		Command->Execute(Event);
	}
}

void nyvux::EventListener::OnDestroyed(Event Event)
{
	for (auto Command : OnDestroyedCommands)
	{
		Command->Execute(Event);
	}
}

void nyvux::EventListener::OnCasted(Event Event)
{
	for (auto Command : OnCastedCommands)
	{
		Command->Execute(Event);
	}
}