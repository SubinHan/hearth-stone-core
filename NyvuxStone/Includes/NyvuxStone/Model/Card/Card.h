#pragma once

#include "../Event/EventListener.h"
#include "CardSpec.h"
#include "CardStat.h"
#include "NyvuxStone/Model/Event/EventNotifier.h"

namespace nyvux
{
	class EventListener;

	class Card : public EventListener, public EventNotifier
	{
	public:
		virtual ~Card() = default;
		Card(const CardSpec Spec);		

		const CardSpec& GetCardSpec();
		
		bool IsGenerated();

	private:
		const CardSpec Spec;
		CardStat CardStat;
	};
}
