#pragma once

#include "../Card/Minion.h"
#include <list>
#include <memory>

namespace nyvux
{
	class Field
	{
	public:
		Field();
		static std::shared_ptr<Field> CreateField();

		void PlaceCard(std::shared_ptr<AbstractPlaceableCard> PlaceableCard, int ColumnNumber);

		int GetNumPlayed();
		std::shared_ptr<AbstractPlaceableCard> GetCardAt(int ZeroBasedIndex);

		bool CanPlace();
		bool IsPlaced(std::shared_ptr<AbstractPlaceableCard> Card);

	private:
		static constexpr int MAX_FIELD_SIZE = 7;

		std::list<std::shared_ptr<AbstractPlaceableCard>> FieldImpl;
	};
}