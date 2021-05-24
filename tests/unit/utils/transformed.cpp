#include <doctest/doctest.h>
#include "utils/transformed.hpp"

TEST_CASE("transformed<T>::vector applies a function to a sequence of T")
{
	const auto actual = utils::transformed<int>(
		std::vector<int>{ 0, 1, 2, 3 }, 
		[](const auto n) noexcept { return n * 3; }
	).vector();
	const auto expected = std::vector<int>{ 0, 3, 6, 9 };
	REQUIRE(actual == expected);
}