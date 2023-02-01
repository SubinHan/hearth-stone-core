#include "NyvuxStone/Model/Player/PlayerException.h"

nyvux::PlayerException::PlayerException(const char* Message)
	: Message(Message)
{
}

const char* nyvux::PlayerException::what() const noexcept
{
	return Message;
}
