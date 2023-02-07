#include "pch.h"

#include "NyvuxStone/Model/Card/Card.h"

namespace nyvux
{
	Card::Card(const CardSpec& Spec) : EventListener(), EventNotifier(), Spec(Spec), CardStat(Spec)
	{
	}

	const CardSpec& Card::GetCardSpec()
	{
		return Spec;
	}

	bool Card::IsGenerated()
	{
		return CardStat.IsGenerated();
	}
}

