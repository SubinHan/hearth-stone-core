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

		void PutMinion(std::shared_ptr<Minion> Minion, int ColumnNumber);

		int GetNumPlayed();
		bool CanPutMinion();

	private:
		static constexpr int MAX_FIELD_SIZE = 7;

		std::list<std::shared_ptr<IPlaceable>> FieldImpl;
	};
}