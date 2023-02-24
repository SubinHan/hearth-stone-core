#pragma once
#include "IEventListener.h"
#include "IEventNotifier.h"

namespace nyvux
{
	class ISecret : public virtual IEventListener, public virtual IEventNotifier
	{
	public:
		virtual ~ISecret() = default;
	};
}
