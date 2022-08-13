#pragma once

namespace r2base
{
	class DebugConfig
	{
	public:
		struct LabelConfig
		{
			bool bShowPositionPivot = true;
		};

	private:
		DebugConfig() = default;

	public:
		static const LabelConfig& GetLabelConfig() { return instance.mLabelConfig; }

	private:
		static DebugConfig instance;

		LabelConfig mLabelConfig;
	};
}