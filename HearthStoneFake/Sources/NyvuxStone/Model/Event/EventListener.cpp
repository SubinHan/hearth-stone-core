#include "pch.h"

#include "NyvuxStone/Model/Event/EventListener.h"

nyvux::EventListener::~EventListener()
{
}

void nyvux::EventListener::OnDrawed(Event Event)
{
	for(auto Command : OnDrawedCommands)
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
