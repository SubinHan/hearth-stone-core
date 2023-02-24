#pragma once
#include "ICharacter.h"

namespace nyvux
{
	class IHero : public virtual ICharacter
	{
	public:
		virtual ~IHero() = default;

		virtual int GetCurrentArmor() const = 0;

		virtual void GainArmor(int Amount) = 0;
	};
}
