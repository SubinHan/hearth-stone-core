#include "pch.h"

#include "NyvuxStone/Model/Event/SecretCondition.h"

nyvux::SecretCondition::SecretCondition(std::shared_ptr<nyvux::Secret> Secret)
	: Secret(Secret)
{
}

void nyvux::SecretCondition::Activate()
{
	Secret->Activate();
}
