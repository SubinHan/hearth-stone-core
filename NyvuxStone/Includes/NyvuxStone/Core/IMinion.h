#pragma once
#include "ICharacter.h"

namespace nyvux
{
	class IMinion : public virtual ICharacter
	{
	public:
		virtual ~IMinion() = default;

		virtual void GainTaunt() = 0;
		virtual void GainCharge() = 0;
		virtual void GainRush() = 0;
		virtual void GainDivineShield() = 0;
		virtual void GainReborn() = 0;
		virtual void Silence() = 0;

		virtual bool HasTaunt() = 0;
		virtual bool HasCharge() = 0;
		virtual bool HasRush() = 0;
		virtual bool HasDivineShield() = 0;
		virtual bool HasReborn() = 0;
	};
}
