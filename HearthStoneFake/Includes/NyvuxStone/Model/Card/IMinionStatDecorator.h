#pragma once

#include <memory>

namespace nyvux
{
	class IMinionStatDecorator
	{
	public:
		IMinionStatDecorator(std::shared_ptr<IMinionStatDecorator> Component);
		virtual int GetDeltaHealth() = 0;
		virtual int GetDeltaAttack() = 0;

	protected:
		std::shared_ptr<IMinionStatDecorator> Component;
	};
}
