#pragma once

#include <memory>
#include <vector>
#include "../HearthStoneFake/Model/Card/Card.h"

namespace nyvux
{
	std::vector<std::shared_ptr<Card>> MakeDummyCards();
}
