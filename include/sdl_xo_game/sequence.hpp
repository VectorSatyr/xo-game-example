#pragma once
#include <vector>

namespace Game
{
	template<class T>
	struct __declspec(novtable) Sequence
	{
		virtual ~Sequence() = default;
		virtual std::vector<T> vector() const = 0;
	};
}