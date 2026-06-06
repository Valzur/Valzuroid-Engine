#pragma once

#ifdef VZ_PLATFORM_WINDOWS
	#ifdef VZ_BUILD_DLL
		#define VALZUROID_API __declspec(dllexport)
	#else
		#define VALZUROID_API __declspec(dllimport)
	#endif
#else
	#error Valzuroid only supports Windows!
#endif