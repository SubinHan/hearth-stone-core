#include "pch.h"

#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorSilence.h"

nyvux::CharacterStatDecoratorSilence::CharacterStatDecoratorSilence(std::shared_ptr<nyvux::CharacterStatDecoratorBase> Component)
	: CharacterStatDecoratorBase(Component)
{
}

int nyvux::CharacterStatDecoratorSilence::GetDeltaHealth()
{
	return 0;
}

int nyvux::CharacterStatDecoratorSilence::GetDeltaAttack()
{
	return 0;
}