#pragma once
#include "IPlaceable.h"

namespace nyvux
{
	class IField
	{
	public:
		virtual ~IField() = 0;
		
		virtual void PlaceCard(std::shared_ptr<IPlaceable> Card, int ColumnNumber) = 0;

		virtual int GetNumPlaced() const = 0;
		virtual std::shared_ptr<IPlaceable> GetCardAt(int ZeroBasedIndex) const = 0;

		virtual bool CanPlace() const = 0;
		virtual bool IsPlaced(std::shared_ptr<IPlaceable> Card) const = 0;
		virtual void Remove(std::shared_ptr<IPlaceable> Card) = 0;
	};
}
