#pragma once
#define FMT_UNICODE 0

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Valzuroid
{
	class VZ_API Log
	{
	public: 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define VZ_CORE_TRACE(...) ::Valzuroid::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VZ_CORE_INFO(...)  ::Valzuroid::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VZ_CORE_WARN(...)  ::Valzuroid::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VZ_CORE_ERROR(...) ::Valzuroid::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VZ_CORE_FATAL(...) ::Valzuroid::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define VZ_TRACE(...)      ::Valzuroid::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VZ_INFO(...)       ::Valzuroid::Log::GetClientLogger()->info(__VA_ARGS__)
#define VZ_WARN(...)       ::Valzuroid::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VZ_ERROR(...)      ::Valzuroid::Log::GetClientLogger()->error(__VA_ARGS__)
#define VZ_FATAL(...)      ::Valzuroid::Log::GetClientLogger()->fatal(__VA_ARGS__)