#include "Field.h"

#include <iterator>

using namespace std;

nyvux::Field::Field() : FieldImpl()
{
}

void nyvux::Field::PutMinion(shared_ptr<Minion> Minion, int ColumnNumber)
{
	if (ColumnNumber < 0)
		ColumnNumber = 0;
	if (ColumnNumber > FieldImpl.size())
		ColumnNumber = FieldImpl.size();

	auto Iter = FieldImpl.begin();
	std::advance(Iter, ColumnNumber);

	FieldImpl.insert(Iter, Minion);
}

int nyvux::Field::GetNumPlayed()
{
	return FieldImpl.size();
}

bool nyvux::Field::CanPutMinion()
{
	return FieldImpl.size() < FIELD_SIZE;
}
