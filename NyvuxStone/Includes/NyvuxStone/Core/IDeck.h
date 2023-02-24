#pragma once
#include "ICard.h"

#include <functional>

namespace nyvux
{
	class IDeck
	{
	public:
		virtual ~IDeck() = default;

		virtual int GetCount() = 0;

		virtual std::shared_ptr<ICard> GetCard(int ZeroBasedIndex) const = 0;
		virtual std::vector<std::shared_ptr<ICard>> GetCards(std::function<bool(std::shared_ptr<ICard>)> Predictor) const = 0;

		virtual std::shared_ptr<ICard> DrawCard() = 0;
		virtual std::shared_ptr<ICard> FindAndDrawCard(std::shared_ptr<ICard> Card) = 0;

		virtual void DestroyCard(int ZeroBasedIndex) = 0;
		virtual void FindAndDestroyCard(std::shared_ptr<ICard> Card) = 0;

		virtual void DredgeCard(int ZeroBasedIndex) = 0;
	};
}
