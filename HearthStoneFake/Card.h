#pragma once

#include <string>
#include <vector>

using namespace std;

namespace nyvux
{
	struct Card
	{
		static constexpr string_view KEY_CARD_ID = "id";
		static constexpr string_view KEY_COLLECTIBLE = "collectible";
		static constexpr string_view KEY_SLUG = "slug";
		static constexpr string_view KEY_CLASS_ID = "classId";
		static constexpr string_view KEY_MULTI_CLASS_IDS = "multiClassIds";
		static constexpr string_view KEY_SPELL_SCHOOL_ID = "spellSchoolId";
		static constexpr string_view KEY_CARD_TYPE_ID = "cardTypeId";
		static constexpr string_view KEY_CARD_SET_ID = "cardSetId";
		static constexpr string_view KEY_RARITY_ID = "rarityId";
		static constexpr string_view KEY_MANA_COST = "manaCost";
		static constexpr string_view KEY_NAME = "name";
		static constexpr string_view KEY_TEXT = "text";
		static constexpr string_view KEY_PARENT_ID = "parentId";
		static constexpr string_view KEY_CHILD_IDS = "childIds";
		static constexpr string_view KEY_KEYWORD_IDS = "keywordIds";

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

		bool operator==(const Card&) const = default;
	};
}
