#pragma once
#include "sequence.hpp"
#include <numeric>

namespace utils
{
	template<class T>
	class iota final : public sequence<T>
	{
	public:
		using size_type = typename std::vector<T>::size_type;

		explicit iota(const size_type len) : iota(len, 0) {};

		explicit iota(const size_type len, const T start) :
			len(len), start(start) {};

		std::vector<T> vector() const override
		{
			std::vector<T> result(len);
			std::iota(result.begin(), result.end(), start);
			return result;
		};

	private:
		const size_type len;
		const T start;
	};
}