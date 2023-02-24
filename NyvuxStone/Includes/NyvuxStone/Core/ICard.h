#pragma once

#include "NyvuxStone/Model/Card/CardSpec.h"
#include "NyvuxStone/Model/Player/Player.h"

namespace nyvux
{
	class ICard
	{
		virtual ~ICard() = default;
		
		virtual std::shared_ptr<Player> GetOwner() const = 0;
		virtual const CardSpec GetCardSpec() const = 0;
		virtual bool IsGenerated() const = 0;
	};
}
