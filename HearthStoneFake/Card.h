#pragma once

#include <string>
#include <vector>

struct Card
{
	int CardId;
	bool Collectible;
	std::string Slug;
	int ClassId;
	std::vector<int> MultiClassIds;
	int SpellSchoolId;
	int CardTypeId;
	int CardSetId;
	int RarityId;
	int ManaCost;
	std::string Name;
	std::string Text;
	int ParentId;
	std::vector<int> ChildIds;
	std::vector<int> KeywordIds;
};