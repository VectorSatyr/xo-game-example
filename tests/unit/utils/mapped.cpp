#include <doctest/doctest.h>
#include "utils/mapped.hpp"

TEST_SUITE("mapped<T>")
{
	TEST_SUITE("mapped<T>::vector()")
	{
		TEST_CASE("Returns a mapped vector of T elements")
		{
			const auto actual = utils::mapped<int>(
				{ 7, 6, 5, 4, 3, 2, 1, 0 }, 4,
				[](const auto n) noexcept { return 6 - n; }).vector();
			const auto expected = std::vector<int>{ 1, 2, 3, 4 };
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns only elements in range of the given vector")
		{
			const auto actual = utils::mapped<unsigned int>(
				{ 2, 4, 6, 8 }, 10,
				[](const auto n) noexcept { return n + 3; }).vector();
			const auto expected = std::vector<unsigned int>{ 8 };
			REQUIRE(actual == expected);
		}
	}
}