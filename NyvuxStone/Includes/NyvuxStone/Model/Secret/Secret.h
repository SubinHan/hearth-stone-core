#pragma once
#include "NyvuxStone/Model/Event/EventListener.h"
#include "NyvuxStone/Model/Event/EventNotifier.h"
#include "NyvuxStone/Core/Game/Command/Spell/ISpellCommand.h"

#include <vector>
#include <memory>

namespace nyvux
{
	class Secret : public EventListener, public EventNotifier
	{
	public:
		Secret(std::vector<std::shared_ptr<ISpellCommand>> Actions);
		void SetCaster(std::shared_ptr<Player> Caster);
		virtual ~Secret() = default;

		virtual void Activate() final;

	protected:
		std::shared_ptr<Player> Caster;
		std::vector<std::shared_ptr<ISpellCommand>> Actions;
	};
}
