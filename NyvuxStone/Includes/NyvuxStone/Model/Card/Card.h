#pragma once

#include "../Event/EventListener.h"
#include "CardSpec.h"
#include "CardStat.h"
#include "NyvuxStone/Model/Event/EventNotifier.h"

#include <memory>

namespace nyvux
{
	class EventListener;

	class Card : public EventListener, public EventNotifier
	{
	public:
		virtual ~Card() = default;
		Card(const CardSpec Spec);		

		void SetOwner(std::shared_ptr<Player> Owner);
		std::shared_ptr<Player> GetOwner();

		const CardSpec& GetCardSpec();
		
		bool IsGenerated();

	protected:
		std::shared_ptr<Player> Owner;

	private:
		const CardSpec Spec;
		CardStat CardStat;

	};
}
