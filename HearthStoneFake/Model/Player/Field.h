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
		void PutMinion(std::shared_ptr<Minion> Minion, int ColumnNumber);

		int GetNumPlayed();
		bool CanPutMinion();

	private:
		static constexpr int FIELD_SIZE = 7;

		std::list<std::shared_ptr<IPlaceable>> FieldImpl;
	};
}