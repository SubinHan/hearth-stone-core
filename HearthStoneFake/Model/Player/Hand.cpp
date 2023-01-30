#include "Hand.h"

#include <algorithm>

using namespace std;

std::shared_ptr<nyvux::Hand> nyvux::Hand::CreateHand()
{
	return make_shared<Hand>();
}

int nyvux::Hand::GetNumCards()
{
	return HandImpl.size();
}

std::shared_ptr<nyvux::Card> nyvux::Hand::GetCard(int ZeroBasedIndex)
{
	return HandImpl[ZeroBasedIndex];
}

std::shared_ptr<nyvux::Card> nyvux::Hand::RemoveCard(int ZeroBasedIndex)
{
	ZeroBasedIndex = clamp(ZeroBasedIndex, 0, static_cast<int>(HandImpl.size()));

	shared_ptr<Card> Removed = *(HandImpl.begin() + ZeroBasedIndex);
	HandImpl.erase(HandImpl.begin() + ZeroBasedIndex);

	return Removed;
}

void nyvux::Hand::AddCard(std::shared_ptr<Card> Card)
{
	if (IsFull())
		return;

	HandImpl.push_back(Card);
}

bool nyvux::Hand::IsFull() const
{
	return HandImpl.size() >= MAX_HAND_SIZE;
}

bool nyvux::Hand::IsEmpty() const
{
	return HandImpl.empty();
}

nyvux::Hand::Hand()
{
}
