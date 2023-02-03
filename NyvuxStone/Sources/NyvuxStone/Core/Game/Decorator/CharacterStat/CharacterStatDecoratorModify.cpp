#include "pch.h"

#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorModify.h"

using namespace std;

nyvux::CharacterStatDecoratorModify::CharacterStatDecoratorModify(
	shared_ptr<nyvux::CharacterStatDecoratorBase> Component, int DeltaAttack, int DeltaHealth)
	: CharacterStatDecoratorBase(Component), DeltaAttack(DeltaAttack), DeltaHealth(DeltaHealth)
{
}

int nyvux::CharacterStatDecoratorModify::GetDeltaHealth()
{
	return DeltaHealth + Component->GetDeltaHealth();
}

int nyvux::CharacterStatDecoratorModify::GetDeltaAttack()
{
	return DeltaAttack + Component->GetDeltaAttack();
}

