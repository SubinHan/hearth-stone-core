#pragma once
#include "MinionStatDecoratorBase.h"

namespace nyvux
{
	class MinionStatDecoratorTaunt : public MinionStatDecoratorBase
	{
	public:
		MinionStatDecoratorTaunt(std::shared_ptr<MinionStatDecoratorBase> Component);
		virtual ~MinionStatDecoratorTaunt();
		bool IsTaunt() override;
	};
}
