#include "Hand.h"

#include <algorithm>

using namespace std;

int nyvux::Hand::GetNumCards()
{
	return HandImpl.size();
}

std::shared_ptr<nyvux::Card> nyvux::Hand::GetCard(int ZeroBasedIndex)
{
	return HandImpl[ZeroBasedIndex];
}

void nyvux::Hand::RemoveCard(int ZeroBasedIndex)
{
	ZeroBasedIndex = clamp(ZeroBasedIndex, 0, static_cast<int>(HandImpl.size()));

	HandImpl.erase(HandImpl.begin() + ZeroBasedIndex);
}

void nyvux::Hand::AddCard(std::shared_ptr<Card> Card)
{
	if (IsFull())
		return;

	HandImpl.push_back(Card);
}

bool nyvux::Hand::IsFull()
{
	return HandImpl.size() >= MAX_HAND_SIZE;
}
