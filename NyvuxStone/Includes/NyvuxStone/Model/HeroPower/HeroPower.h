#pragma once
#include "NyvuxStone/Model/Card/Character.h"

#include <memory>

namespace nyvux
{
	class HeroPowerException;

	class HeroPower
	{
	public:
		HeroPower(bool NeedTarget, int Cost);
		bool NeedTarget();
		virtual void Use() noexcept(false);
		virtual void UseTo(std::shared_ptr<Character> Target) noexcept(false);

		int GetCost();

	protected:
		bool bNeedTarget;
		int Cost;
	};

	class HeroPowerException : public std::exception
	{
	public:
		HeroPowerException(const char* Message);

		const char* what() const noexcept override;

	private:
		const char* Message;
	};
}
