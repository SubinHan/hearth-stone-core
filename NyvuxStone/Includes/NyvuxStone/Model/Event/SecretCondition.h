#pragma once
#include "EventListener.h"
#include "NyvuxStone/Model/Card/Secret.h"

#include <memory>

namespace nyvux
{
	class SecretCondition : public EventListener
	{
	public:
		SecretCondition(std::shared_ptr<Secret> Secret);
		virtual ~SecretCondition() = default;

		virtual void Activate() final;

	private:
		std::shared_ptr<Secret> Secret;
	};
}
