#pragma once

#include "CardSpec.h"
#include "CardStat.h"

namespace nyvux
{
	class Card
	{
	public:
		Card(const CardSpec& Spec);
		const CardSpec& GetCardSpec();

	private:
		const CardSpec& Spec;
		CardStat CardStat;
	};
}