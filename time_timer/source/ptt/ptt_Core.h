#pragma once

#include <memory>

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;
	class Core
	{
	private:
		Core() = default;

	public:
		static CoreUp Create();
	};
}