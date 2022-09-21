#pragma once

#include <functional>

namespace r2bix_director
{
	struct Config;

	class Scheduler
	{
	private:
		using ProcessorT = std::function<void()>;

	public:
		Scheduler( const Config& config, const std::function<void(float)> scene_update_func, const std::function<void()> scene_render_func );

		void Do();

	private:
		const ProcessorT mProcessor;
	};
}