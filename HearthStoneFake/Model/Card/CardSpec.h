#pragma once

#include <string>
#include <vector>

namespace nyvux
{
	struct CardSpec
	{
		static constexpr std::string_view KEY_CARD_ID = "id";
		static constexpr std::string_view KEY_COLLECTIBLE = "collectible";
		static constexpr std::string_view KEY_SLUG = "slug";
		static constexpr std::string_view KEY_CLASS_ID = "classId";
		static constexpr std::string_view KEY_MULTI_CLASS_IDS = "multiClassIds";
		static constexpr std::string_view KEY_SPELL_SCHOOL_ID = "spellSchoolId";
		static constexpr std::string_view KEY_CARD_TYPE_ID = "cardTypeId";
		static constexpr std::string_view KEY_CARD_SET_ID = "cardSetId";
		static constexpr std::string_view KEY_RARITY_ID = "rarityId";
		static constexpr std::string_view KEY_HEALTH = "health";
		static constexpr std::string_view KEY_ATTACK = "attack";
		static constexpr std::string_view KEY_MANA_COST = "manaCost";
		static constexpr std::string_view KEY_NAME = "name";
		static constexpr std::string_view KEY_TEXT = "text";
		static constexpr std::string_view KEY_PARENT_ID = "parentId";
		static constexpr std::string_view KEY_CHILD_IDS = "childIds";
		static constexpr std::string_view KEY_KEYWORD_IDS = "keywordIds";

		int CardId;
		bool Collectible;
		std::string Slug;
		int ClassId;
		std::vector<int> MultiClassIds;
		int SpellSchoolId;
		int CardTypeId;
		int CardSetId;
		int RarityId;
		int Health;
		int Attack;
		int ManaCost;
		std::string Name;
		std::string Text;
		int ParentId;
		std::vector<int> ChildIds;
		std::vector<int> KeywordIds;

		bool operator==(const CardSpec&) const = default;
	};
}
