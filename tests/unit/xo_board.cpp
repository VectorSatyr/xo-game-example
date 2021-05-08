#include <doctest/doctest.h>

TEST_CASE("XOBoard::full returns true when every cell of the board is occupied")
{
	auto actual = Game::XOBoard(3, 3, { 1, 1, 1, 1, 1, 1, 1, 1, 1 }).full();
	auto expected = true;
	REQUIRE(actual == expected);
}