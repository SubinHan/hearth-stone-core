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
		bool CanPlace();

	private:
		static constexpr int MAX_FIELD_SIZE = 7;

		std::list<std::shared_ptr<AbstractPlaceableCard>> FieldImpl;
	};
}