#include "EventListener.h"

nyvux::EventListener::~EventListener()
{
}

void nyvux::EventListener::OnDrawed(Event Event)
{
	for(auto Command : OnDrawedCommands)
	{
		Command->execute(Event);
	}
}

void nyvux::EventListener::OnDamaged(Event Event)
{
	for (auto Command : OnDamagedCommands)
	{
		Command->execute(Event);
	}
}

void nyvux::EventListener::OnHealed(Event Event)
{
	for (auto Command : OnHealedCommands)
	{
		Command->execute(Event);
	}
}

void nyvux::EventListener::OnSummoned(Event Event)
{
	for (auto Command : OnSummonedCommands)
	{
		Command->execute(Event);
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
