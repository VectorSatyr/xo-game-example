#pragma once
#include <vector>

namespace utils
{
	template<class T>
	struct __declspec(novtable) sequence
	{
		virtual ~sequence() = default;
		virtual std::vector<T> vector() const = 0;
	};
}