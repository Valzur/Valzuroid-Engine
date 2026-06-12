#pragma once

#ifdef VZ_PLATFORM_WINDOWS
	#ifdef VZ_BUILD_DLL
		#define VZ_API __declspec(dllexport)
	#else
		#define VZ_API __declspec(dllimport)
	#endif
#else
	#error Valzuroid only supports Windows!
#endif

#ifdef VZ_DEBUG
	#define VZ_ENABLE_ASSERTS
#endif

#ifdef VZ_ENABLE_ASSERTS
	#define VZ_ASSERT(x, ...) { if(!(x)) { VZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VZ_CORE_ASSERT(x, ...) { if(!(x)) { VZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VZ_ASSERT(x, ...)
	#define VZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)