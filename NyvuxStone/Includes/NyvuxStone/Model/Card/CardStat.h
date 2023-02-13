#pragma once
#include <memory>

#include "CardSpec.h"
#include "NyvuxStone/Core/Game/Decorator/CardStat/ICardStatDecorator.h"

namespace nyvux
{
	class CardStat
	{
	public:
		CardStat(const CardSpec Spec);

		template<class DecoratorType, class... Types>
		void Modify(Types... Args);

		int GetManaCost();
		bool IsGenerated();

	private:
		void CorrectCurrentManaCost();

	private:
		const CardSpec Spec;
		std::shared_ptr<ICardStatDecorator> Decorator;

		int CurrentManaCost;
		bool bIsGenerated;
		
	};

	template <class DecoratorType, class ... Types>
	void CardStat::Modify(Types... Args)
	{
		Decorator = std::make_shared<DecoratorType>(Decorator, Args...);
	}
}
