#pragma once
#include "repch.h"
#include "spdlog/spdlog.h"

#define DEBUG

#ifdef DEBUG

#define LOG_INF(x) spdlog::info(x)
#define LOG_ERR(x) spdlog::error(x)
#define LOG_WARN(x) spdlog::warn(x)
#define LOG_CRITICAL(x) spdlog::critical(x)

#else

#define LOG_INF(x) 
#define LOG_ERR(x) 
#define LOG_WARN(x)
#define LOG_CRITICAL(x)

#endif

namespace RE {

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T>
	using Scope = std::unique_ptr<T>;
}
