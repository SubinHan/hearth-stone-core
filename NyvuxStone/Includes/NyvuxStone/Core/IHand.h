#pragma once
#include "ICard.h"

#include <memory>

namespace nyvux
{
	class IHand
	{
	public:
		virtual ~IHand() = default;

		virtual int GetCount() const = 0;
		virtual std::shared_ptr<ICard> GetCard(int ZeroBasedIndex) const = 0;
		virtual std::shared_ptr<ICard> RemoveCard(int ZeroBasedIndex) = 0;
		virtual std::shared_ptr<ICard> AddCard(std::shared_ptr<ICard> Card) = 0;

		virtual bool IsFull() const = 0;
		virtual bool IsEmpty() const = 0;
	};
}
