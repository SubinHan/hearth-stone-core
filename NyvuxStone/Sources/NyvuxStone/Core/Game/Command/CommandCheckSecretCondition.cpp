#include "pch.h"

#include "NyvuxStone/Core/Game/Command/CommandCheckSecretCondition.h"

nyvux::CommandCheckSecretCondition::CommandCheckSecretCondition(std::shared_ptr<nyvux::Secret> Secret, std::vector<std::shared_ptr<SecretCondition>> SecretConditions)
	: Secret(Secret),
	SecretConditions(SecretConditions)
{
}

void nyvux::CommandCheckSecretCondition::Execute(std::shared_ptr<nyvux::NyvuxStoneEvent> Event)
{
	for(auto SecretCondition : SecretConditions)
	{
		if (!SecretCondition->IsTrue())
			return;
	}

	Secret->Activate();
}
