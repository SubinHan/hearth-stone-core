#pragma once

namespace nyvux
{
	class ISecretZone
	{
	public:
		virtual ~ISecretZone() = default;

		virtual bool CanAddSecret() const = 0;
		virtual void RegisterSecret(std::shared_ptr<ISecret> Secret) = 0;
		virtual void UnregisterSecret(std::shared_ptr<ISecret> Secret) = 0;
	};
}