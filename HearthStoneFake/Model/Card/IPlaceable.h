#pragma once

class IPlaceable
{
public:
	virtual bool CanBeAttackTarget() = 0;
	virtual bool CanBeSpellTarget() = 0;
};