#pragma once

#include "../Event/EventListener.h"
#include "CardSpec.h"
#include "CardStat.h"

namespace nyvux
{
	class EventListener;

	class Card : public EventListener
	{
	public:
		virtual ~Card() = default;
		Card(const CardSpec& Spec);		

		const CardSpec& GetCardSpec();
		
		bool IsGenerated();

	private:
		const CardSpec& Spec;
		CardStat CardStat;
	};
}