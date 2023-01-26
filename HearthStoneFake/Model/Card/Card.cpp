#include "Card.h"

namespace nyvux
{
	Card::Card(const CardSpec& Spec) : Spec(Spec), CardStat(Spec)
	{
	}

	const CardSpec& Card::GetCardSpec()
	{
		return Spec;
	}
}

