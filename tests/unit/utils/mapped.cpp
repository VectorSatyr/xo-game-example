#include <doctest/doctest.h>
#include "utils/mapped.hpp"

TEST_SUITE("mapped<T>")
{
	TEST_SUITE("mapped<T>::vector()")
	{
		TEST_CASE_TEMPLATE_DEFINE(
			"Returns a mapped vector", T, mapped_default
		)
		{
			const auto actual = utils::mapped<T>(
				{ 7, 6, 5, 4, 3, 2, 1, 0 }, 4,
				[](const auto n) noexcept { return 6 - n; }).vector();
			const auto expected = std::vector<T>{ 1, 2, 3, 4 };
			REQUIRE(actual == expected);
		}

		TEST_CASE_TEMPLATE_DEFINE(
			"Returns only elements in range of the given vector", 
			T, mapped_in_range
		)
		{
			const auto actual = utils::mapped<T>(
				{ 2, 4, 6, 8 }, 10,
				[](const auto n) noexcept { return n + 3; }).vector();
			const auto expected = std::vector<T>{ 8 };
			REQUIRE(actual == expected);
		}

		TEST_CASE_TEMPLATE_INVOKE(
			mapped_default, int, unsigned int, std::size_t);
		TEST_CASE_TEMPLATE_INVOKE(
			mapped_in_range, int, unsigned int, std::size_t);
	}
}