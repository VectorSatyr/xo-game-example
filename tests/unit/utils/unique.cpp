#include <doctest/doctest.h>
#include "utils/unique.hpp"

TEST_CASE("unique<T>::vector returns a sequence of unique T values")
{
	const auto actual = utils::unique<int>({ 5, 5, 5, 4, 5 }).vector();
	const auto expected = std::vector<int>{ 5, 4 };
	REQUIRE(actual == expected);
}