#include "Card.h"

namespace nyvux
{
	Card::Card(const CardSpec& Spec) : EventListener(), Spec(Spec), CardStat(Spec)
	{
	}

	const CardSpec& Card::GetCardSpec()
	{
		return Spec;
	}
}

