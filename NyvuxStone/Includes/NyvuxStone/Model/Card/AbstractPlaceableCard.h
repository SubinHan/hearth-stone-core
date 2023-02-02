#pragma once

#include "Card.h"
#include "CardSpec.h"

namespace nyvux
{
	class AbstractPlaceableCard : public Card
	{
	public:
		AbstractPlaceableCard(const CardSpec& Spec);
		virtual ~AbstractPlaceableCard() = default;
		virtual bool CanBeAttackTarget() = 0;
		virtual bool CanBeSpellTarget() = 0;
	};
}

