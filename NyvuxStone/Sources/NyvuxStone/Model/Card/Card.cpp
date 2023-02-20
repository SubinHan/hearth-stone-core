#include "pch.h"

#include "NyvuxStone/Model/Card/Card.h"

namespace nyvux
{
	Card::Card(const CardSpec Spec) : EventListener(), EventNotifier(), Spec(Spec), CardStat(Spec)
	{
	}

	void Card::SetOwner(std::shared_ptr<Player> Owner)
	{
		this->Owner = Owner;
	}

	std::shared_ptr<Player> Card::GetOwner()
	{
		return Owner;
	}

	const CardSpec& Card::GetCardSpec()
	{
		return Spec;
	}

	bool Card::IsGenerated()
	{
		return CardStat.IsGenerated();
	}
}

