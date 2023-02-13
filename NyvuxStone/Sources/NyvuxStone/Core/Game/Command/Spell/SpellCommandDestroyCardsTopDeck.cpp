#include "pch.h"

#include "NyvuxStone/Core/Game/Command/Spell/SpellCommandDestroyCardsTopDeck.h"

nyvux::SpellCommandDestroyCardsTopDeck::SpellCommandDestroyCardsTopDeck(std::shared_ptr<Player> Target,
	const int Amount)
		: Target(Target), Amount(Amount)
{
}

void nyvux::SpellCommandDestroyCardsTopDeck::Execute(std::shared_ptr<Character> Target)
{
	for(int i = 0; i < Amount; i++)
	{
		this->Target->DestroyTopCardsInDeck();
	}
}
