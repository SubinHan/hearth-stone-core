#include "CardStatVanilla.h"

nyvux::CardStatVanilla::CardStatVanilla(CardSpec Spec) : Spec(Spec)
{

}

nyvux::CardStatVanilla::~CardStatVanilla()
{
}

int nyvux::CardStatVanilla::GetMaxHealth()
{
	return Spec.Health;
}

int nyvux::CardStatVanilla::GetAttack()
{
	return Spec.Attack;
}
