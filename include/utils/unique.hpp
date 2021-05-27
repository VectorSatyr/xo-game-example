#pragma once
#include "sequence.hpp"
#include "variant.hpp"
#include <memory>
#include <algorithm>
#include <unordered_set>

namespace utils
{
	template<class T>
	class unique final : public sequence<T>
	{
	public:
		explicit unique(const std::initializer_list<T> init) : 
			unique(std::unique_ptr<sequence<T>>(new variant<T>(init))) {};

		explicit unique(std::unique_ptr<sequence<T>> origin) : 
			origin(std::move(origin)) {};

		std::vector<T> vector() const override
		{
			const auto vector = origin->vector();
			std::vector<T> result;
			std::unordered_set<T> hash;
			std::for_each(vector.begin(), vector.end(), 
				[&result, &hash](const auto elem) {
					if (hash.count(elem) == 0) {
						hash.insert(elem);
						result.push_back(elem);
					}
				});
			return result;
		};

	private:
		const std::unique_ptr<sequence<T>> origin;
	};
}