#include "pch.h"

#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorBase.h"

nyvux::CharacterStatDecoratorBase::CharacterStatDecoratorBase()
	: CharacterStatDecoratorBase(nullptr)
{
}

nyvux::CharacterStatDecoratorBase::CharacterStatDecoratorBase(std::shared_ptr<CharacterStatDecoratorBase> Component)
	: Component(Component)
{
}

int nyvux::CharacterStatDecoratorBase::GetDeltaHealth()
{
	if (!Component)
		return 0;

	return Component->GetDeltaHealth();
}

int nyvux::CharacterStatDecoratorBase::GetDeltaAttack()
{
	if (!Component)
		return 0;

	return Component->GetDeltaAttack();
}