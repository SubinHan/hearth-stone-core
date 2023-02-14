#include "pch.h"

#include "NyvuxStone/Model/Player/SecretZone.h"

#include "NyvuxStone/Model/Player/PlayerException.h"

std::shared_ptr<nyvux::SecretZone> nyvux::SecretZone::CreateSecretZone()
{
	return std::make_shared<SecretZone>();
}

void nyvux::SecretZone::RegisterSecret(std::shared_ptr<Secret> Secret, std::shared_ptr<GameMediator> GameMediator)
{
	if(!CanAddSecret())
	{
		throw PlayerException("Secert zone is full.");
	}

	GameMediator->RegisterCard(Secret);
	SecretZoneImpl.push_back(Secret);
}

bool nyvux::SecretZone::CanAddSecret() const noexcept
{
	return SecretZoneImpl.size() < MAX_CAPACITY;
}

void nyvux::SecretZone::UnregisterSecret(std::shared_ptr<Secret> Secret, std::shared_ptr<GameMediator> GameMediator)
{
	GameMediator->UnregisterCard(Secret);
	SecretZoneImpl.remove(Secret);
}
