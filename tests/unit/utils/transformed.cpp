#include <doctest/doctest.h>
#include "utils/transformed.hpp"

TEST_CASE("transformed<T>::vector applies a function to a sequence of T")
{
	const auto actual = utils::transformed<int>(
		{ 1, 3, 2, 5 }, [](const auto n) noexcept { return n * 3; }
	).vector();
	const auto expected = std::vector<int>{ 3, 9, 6, 15 };
	REQUIRE(actual == expected);
}