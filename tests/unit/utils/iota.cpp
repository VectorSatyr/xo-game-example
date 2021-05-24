#include <doctest/doctest.h>
#include "utils/iota.hpp"

TEST_CASE("iota<T>::vector returns an array of consecutive T values")
{
	const auto actual = utils::iota<int>(7, 2).vector();
	const auto expected = std::vector<int>{ 2, 3, 4, 5, 6, 7, 8 };
	REQUIRE(actual == expected);
}

TEST_CASE("iota<T>::vector starts from 0 by default")
{
	const auto actual = utils::iota<unsigned int>(5).vector();
	const auto expected = std::vector<unsigned int>{ 0, 1, 2, 3, 4 };
	REQUIRE(actual == expected);
}