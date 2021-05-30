#pragma once
#include "sequence.hpp"
#include <functional>

namespace utils
{
	template<class T>
	class mapped final :
		public utils::sequence<T>
	{
	public:
		using size_type = typename std::vector<T>::size_type;

		mapped(
			const std::vector<T> seq,
			const size_type len,
			const std::function<size_type(const size_type)> pred
		) : seq(seq), len(len), pred(pred) {};

		std::vector<T> vector() const override
		{
			const auto size(seq.size());
			std::vector<T> result;
			for (size_type n = 0; n < len; ++n) {
				auto pos = pred(n);
				if (pos < size) result.push_back(seq.at(pos));
			}
			return result;
		};

	private:
		const std::vector<T> seq;
		const size_type len;
		const std::function<size_type(const size_type)> pred;
	};
}