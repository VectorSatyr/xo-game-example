#include <doctest/doctest.h>
#include "utils/mapped.hpp"

TEST_CASE("mapped<T>::vector returns a mapped vector of T")
{
	const auto actual = utils::mapped<int>(
		{ 7, 6, 5, 4, 3, 2, 1, 0 }, 4, 
		[](const auto n) noexcept { return 6 - n; }).vector();
	const auto expected = std::vector<int>{ 1, 2, 3, 4 };
	REQUIRE(actual == expected);
}

TEST_CASE("mapped<T>::vector returns only elements in range")
{
	const auto actual = utils::mapped<unsigned int>(
		{ 2, 4, 6, 8 }, 10,
		[](const auto n) noexcept { return n + 3; }).vector();
	const auto expected = std::vector<unsigned int>{ 8 };
	REQUIRE(actual == expected);
}