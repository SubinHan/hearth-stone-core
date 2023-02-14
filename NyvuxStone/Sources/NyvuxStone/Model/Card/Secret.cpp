#include "pch.h"

#include "NyvuxStone/Model/Card/Secret.h"

std::shared_ptr<nyvux::Secret> nyvux::Secret::CreateSecret(const CardSpec CardSpec)
{
	return std::make_shared<Secret>(CardSpec);
}

nyvux::Secret::Secret(const CardSpec CardSpec)
	: Spell(CardSpec)
{
}

void nyvux::Secret::Cast(std::shared_ptr<Player> Caster, std::shared_ptr<Character> Target)
{
	if (!(Caster->CanAddSecret()))
		return;

	Caster->AddSecret(shared_from_this());
	this->Caster = Caster;
}

void nyvux::Secret::Activate()
{
	Caster->RemoveSecret(shared_from_this());
	Spell::Cast(Caster, nullptr);
}
