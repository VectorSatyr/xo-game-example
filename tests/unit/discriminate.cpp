#include <doctest/doctest.h>
#include "sdl_xo_game/discriminate.hpp"

TEST_CASE("Discriminate<T>::vector returns a discriminated vector of T")
{
	using size = Game::Discriminate<int>::size_type;
	const auto actual = Game::Discriminate<int>(
		{ 7, 6, 5, 4, 3, 2, 1, 0 }, 4, 
		[](const size n) noexcept { return 6 - n; }).vector();
	const auto expected = std::vector<int>{ 1, 2, 3, 4 };
	REQUIRE(actual == expected);
}

TEST_CASE("Discriminate<T>::vector returns only elements in range")
{
	using size = Game::Discriminate<unsigned int>::size_type;
	const auto actual = Game::Discriminate<unsigned int>(
		{ 2, 4, 6, 8 }, 10,
		[](const size n) noexcept { return n + 3; }).vector();
	const auto expected = std::vector<unsigned int>{ 8 };
	REQUIRE(actual == expected);
}