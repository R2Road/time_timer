#pragma once

namespace ptt
{
	class DebugConfig
	{
	private:
		DebugConfig() = delete;

	public:
		struct NodeConfig
		{
			bool pivot = true;
		};
		static const NodeConfig& GetNodeConfig()
		{
			const static NodeConfig ret;
			return ret;
		}
	};
}