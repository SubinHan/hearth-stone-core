#pragma once
#include "Card.h"

namespace nyvux
{
	class Weapon : public Card
	{
	public:
		static std::shared_ptr<Weapon> CreateWeapon(const CardSpec CardSpec);

		Weapon(const CardSpec CardSpec);

		int GetAttack();
		int GetDurability();

		bool HasPoison();
		bool HasWindfury();
		bool HasLifesteal();

	private:
		int Attack;
		int Durability;
	};
}
