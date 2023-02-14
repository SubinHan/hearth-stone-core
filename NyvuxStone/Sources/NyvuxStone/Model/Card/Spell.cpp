#include "pch.h"

#include "NyvuxStone/Model/Card/Spell.h"


std::shared_ptr<nyvux::Spell> nyvux::Spell::CreateSpell(const CardSpec CardSpec)
{
	return std::make_shared<Spell>(CardSpec);
}

nyvux::Spell::Spell(const CardSpec CardSpec)
	: Card(CardSpec),
	bNeedsTarget(false)
{
}

void nyvux::Spell::AddSpellCommand(std::shared_ptr<ISpellCommand> Command)
{
	SpellCommands.push_back(Command);
}

void nyvux::Spell::Cast(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target)
{
	for (auto Command : SpellCommands)
	{
		Command->Execute(Caster, Target);
	}
}

bool nyvux::Spell::NeedsTarget()
{
	return bNeedsTarget;
}

void nyvux::Spell::SetNeedsTarget(bool NeedsTarget)
{
	bNeedsTarget = NeedsTarget;
}
