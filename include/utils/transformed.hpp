#pragma once
#include "sequence.hpp"
#include <functional>
#include <algorithm>

namespace utils
{
	template<class T>
	class transformed final : public sequence<T>
	{
	public:
		explicit transformed(
			const sequence<T>& origin,
			const std::function<T(const T&)> func
		) : origin(origin), func(func) {}

		std::vector<T> vector() const override
		{
			const auto vector = origin.vector();
			std::vector<T> result(vector.size());
			std::transform(
				vector.begin(), vector.end(), result.begin(), func
			);
			return result;
		};

	private:
		const sequence<T>& origin;
		const std::function<T(const T&)> func;
	};
}