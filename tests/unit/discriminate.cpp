#include <doctest/doctest.h>
#include "sdl_xo_game/discriminate.hpp"

TEST_CASE("Discriminate<T>::vector returns a discriminated vector of T")
{
	const auto actual = Game::Discriminate<int>(
		{ 7, 6, 5, 4, 3, 2, 1, 0 }, 4, 
		[](const Game::Discriminate<int>::size_type n) noexcept {
			return 6 - n;
		}).vector();
	const auto expected = std::vector<int>{ 1, 2, 3, 4 };
	REQUIRE(actual == expected);
}