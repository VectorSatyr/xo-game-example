#pragma once
#include "sequence.hpp"
#include "variant.hpp"
#include <memory>
#include <functional>
#include <algorithm>

namespace utils
{
	template<class T>
	class transformed final : public sequence<T>
	{
	public:
		explicit transformed(
			const std::initializer_list<T> init,
			const std::function<T(const T&)> func
		) : transformed(
			std::unique_ptr<sequence<T>>(new variant<T>(init)), func) {};

		explicit transformed(
			std::unique_ptr<sequence<T>> origin,
			const std::function<T(const T&)> func
		) : origin(std::move(origin)), func(func) {}

		std::vector<T> vector() const override
		{
			const auto vector = origin->vector();
			std::vector<T> result(vector.size());
			std::transform(
				vector.begin(), vector.end(), result.begin(), func
			);
			return result;
		};

	private:
		const std::unique_ptr<sequence<T>> origin;
		const std::function<T(const T&)> func;
	};
}