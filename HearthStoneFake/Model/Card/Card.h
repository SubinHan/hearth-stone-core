#pragma once

#include "CardSpec.h"
#include "CardStat.h"

namespace nyvux
{
	class Card
	{
	public:
		virtual ~Card() = default;
		Card(const CardSpec& Spec);		

		const CardSpec& GetCardSpec();

	private:
		const CardSpec& Spec;
		CardStat CardStat;
	};
}