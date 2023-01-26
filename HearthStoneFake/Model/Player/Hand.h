#pragma once

#include "../Card/Card.h"

#include <vector>
#include <memory>

namespace nyvux
{
	class Hand
	{
	public:
		int GetNumCards();
		std::shared_ptr<Card> GetCard(int ZeroBasedIndex);

		void RemoveCard(int ZeroBasedIndex);
		void AddCard(std::shared_ptr<Card> Card);

		bool IsFull();
		

	private:
		static constexpr int MAX_HAND_SIZE = 10;

		std::vector<std::shared_ptr<Card>> HandImpl;

		bool bIsFull;
	};

}