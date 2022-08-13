#pragma once

namespace ptt
{
	class Config
	{
	private:
		Config() = delete;

	public:
		struct NodeConfig
		{
			bool pivot = false;
		};
		static const NodeConfig& GetNodeConfig()
		{
			const static NodeConfig ret
			{
				false
			};
			return ret;
		}
	};
}