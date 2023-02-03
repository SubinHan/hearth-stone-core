#include "pch.h"

#include "NyvuxStone/Model/HeroPower/HeroPower.h"

nyvux::HeroPower::HeroPower(bool NeedTarget, int Cost)
	: bNeedTarget(NeedTarget), Cost(Cost)
{
}

bool nyvux::HeroPower::NeedTarget()
{
	return bNeedTarget;
}

void nyvux::HeroPower::Use()
{
	throw HeroPowerException("Undefined behavior: The hero power cannot be used without a target");
}

void nyvux::HeroPower::UseTo(std::shared_ptr<Character> Target)
{
	throw HeroPowerException("Undefined behavior: The hero power doesn't need a target");
}

int nyvux::HeroPower::GetCost()
{
	return Cost;
}

nyvux::HeroPowerException::HeroPowerException(const char* Message)
{
	this->Message = Message;
}

const char* nyvux::HeroPowerException::what() const noexcept
{
	return Message;
}
