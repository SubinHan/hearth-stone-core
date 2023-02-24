#pragma once
#include "IPlaceable.h"

namespace nyvux
{
	class ICharacter : public virtual IPlaceable
	{
	public:
		virtual ~ICharacter() = default;

		virtual void GainDamage(const int Amount) = 0;
		virtual void GainHeal(const int Amount) = 0;
		virtual void Destroy() = 0;

		virtual int GetMaxHealth() = 0;
		virtual int GetAttack() = 0;
		virtual int GetCurrentHealth() = 0;

		virtual bool CanAttack() = 0;
		
		virtual bool HasImmune() = 0;
		virtual bool HasFreeze() = 0;
		virtual bool HasStealth() = 0;
		virtual bool HasWindfury() = 0;
		virtual bool HasPoisonous() = 0;
		virtual bool HasLifesteal() = 0;
	};
}
