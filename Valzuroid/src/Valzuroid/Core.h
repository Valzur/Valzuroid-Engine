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

#define BIT(x) (1 << x)