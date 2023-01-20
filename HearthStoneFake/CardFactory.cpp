#include "CardFactory.h"
#include "CardFactory.h"
#include "CardSpecRepository.h"

namespace nyvux
{
	Card CardFactory::CreateCardById(int Id)
	{
		CardSpecRepository& Repo = CardSpecRepository::GetInstance();

		return Card(Repo.GetCardSpecById(Id));
	}

	Card CardFactory::CreateDummyCard()
	{
		CardSpecRepository& Repo = CardSpecRepository::GetInstance();

		return Card(Repo.DUMMY_CARDSPEC);
	}

}

