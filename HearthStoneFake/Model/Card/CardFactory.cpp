#include "CardFactory.h"
#include "CardSpecRepository.h"

using namespace std;

namespace nyvux
{
	std::shared_ptr<Card> CardFactory::CreateCardById(const int Id)
	{
		CardSpecRepository& Repo = CardSpecRepository::GetInstance();

		return make_shared<Card>(Repo.GetCardSpecById(Id));
	}

	std::shared_ptr<Card> CardFactory::CreateDummyCard()
	{
		CardSpecRepository& Repo = CardSpecRepository::GetInstance();

		return make_shared<Card>(Repo.DUMMY_CARDSPEC);
	}

	std::shared_ptr<Minion> CardFactory::CreateMinionById(const int Id)
	{
		CardSpecRepository& Repo = CardSpecRepository::GetInstance();

		return make_shared<Minion>(Repo.GetCardSpecById(Id));
	}

	std::shared_ptr<Minion> CardFactory::CreateMinionBySpec(const CardSpec& Spec)
	{
		return make_shared<Minion>(Spec);
	}
}

