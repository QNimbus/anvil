#pragma once

#include <filesystem>

#define AV_EXPAND_MACRO(x) x
#define AV_STRINGIFY_MACRO(x) #x

#ifdef AV_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define AV_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { AV##type##ERROR(msg, __VA_ARGS__); AV_DEBUGBREAK(); } }
#define AV_INTERNAL_ASSERT_WITH_MSG(type, check, ...) AV_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define AV_INTERNAL_ASSERT_NO_MSG(type, check) AV_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", AV_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define AV_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define AV_INTERNAL_ASSERT_GET_MACRO(...) AV_EXPAND_MACRO( AV_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, AV_INTERNAL_ASSERT_WITH_MSG, AV_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define AV_ASSERT(...) AV_EXPAND_MACRO( AV_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define AV_CORE_ASSERT(...) AV_EXPAND_MACRO( AV_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define AV_ASSERT(...)
#define AV_CORE_ASSERT(...)
#endif

