#pragma once
#include <atomic>
using ID = uint32_t;

inline static ID idGenerator()
{
	static std::atomic<ID> id{ 1 };
	return ++id;
}

template<typename T>
struct type { static void id() {} };

template<typename T>
inline constexpr ID getTypeID() 
{
	return static_cast<ID>(reinterpret_cast<size_t>(&type<T>::id));
}