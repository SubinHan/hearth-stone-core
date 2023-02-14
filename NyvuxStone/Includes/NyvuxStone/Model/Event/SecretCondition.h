#pragma once
#include "EventListener.h"

namespace nyvux
{
	class SecretCondition : public EventListener
	{
	public:
		SecretCondition() = default;
		virtual ~SecretCondition() = default;
		virtual bool IsTrue();

	private:
		bool bIsTrue;
	};
}
