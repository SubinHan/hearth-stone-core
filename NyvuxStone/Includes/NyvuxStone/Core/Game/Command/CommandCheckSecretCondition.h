#pragma once
#include "ICommand.h"
#include "NyvuxStone/Model/Card/Secret.h"

namespace nyvux
{
	class CommandCheckSecretCondition : public ICommand
	{
	public:
		CommandCheckSecretCondition(std::shared_ptr<Secret> Secret, std::vector<std::shared_ptr<SecretCondition>> SecretConditions);
		void Execute(std::shared_ptr<NyvuxStoneEvent> Event) override;

	private:
		std::shared_ptr<Secret> Secret;
		std::vector<std::shared_ptr<SecretCondition>> SecretConditions;
	};
}
