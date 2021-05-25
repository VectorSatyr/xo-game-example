#include <doctest/doctest.h>
#include "utils/variant.hpp"

TEST_CASE("variant<T>::vector returns a custom sequence of T values")
{
	const auto actual = utils::variant<int>( 1, 2, 4, 8 ).vector();
	const auto expected = std::vector<int>{ 1, 2, 4, 8 };
	REQUIRE(actual == expected);
}