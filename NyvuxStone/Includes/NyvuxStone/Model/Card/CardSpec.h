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

	enum KEYWORD
	{
		TAUNT = 1,
		SPELL_DAMAGE = 2,
		SPELLPOWER = 2,
		DIVINE_SHIELD = 3,
		CHARGE = 4,
		SECRET = 5,
		STEALTH = 6,
		BATTLECRY = 8,
		FREEZE = 10,
		WINDFURY = 11,
		DEATHRATTLE = 12,
		COMBO = 13,
		OVERLOAD = 14,
		SILENCE = 15,
		COUNTER = 16,
		IMMUNE = 17,
		SPARE_PART = 19,
		INSPIRE = 20,
		DISCOVER = 21,
		QUEST = 31,
		POISONOUS = 32,
		ADAPT = 34,
		LIFESTEAL = 38,
		RECRUIT = 39,
		ECHO = 52,
		RUSH = 53,
		OVERKILL = 61,
		START_OF_GAME = 64,
		MAGNETIC = 66,
		MODULAR = 66,
		EVILZUG = 71,
		LACKEY = 71,
		TWINSPELL = 76,
		MEGA_WINDFURY = 77,
		REBORN = 78,
		INVOKE = 79,
		EMPOWER = 79,
		OUTCAST = 86,
		SPELLBURST = 88,
		SIDEQUEST = 89,
		CORRUPT = 91,
		QUESTLINE = 96,
		TRADEABLE = 97,
		FRENZY = 99,
		HONORABLE_KILL = 100,
		SPELL_POWER_NATURE = 104,
		NATURE_SPELL_DAMAGE = 104,
		COLOSSAL = 231,
		DREDGE = 232,
		INFUSE = 238,
		CORPSE = 247,
		MANATHIRST = 257,
	};
}
