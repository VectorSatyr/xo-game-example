#include <doctest/doctest.h>
#include "sdl_xo_game/xo_board.hpp"

TEST_CASE("XOBoard::full returns true when every cell of the board is occupied")
{
	auto actual = Game::XOBoard(3, 3, { 1, 1, 1, 1, 1, 1, 1, 1, 1 }).full();
	auto expected = true;
	REQUIRE(actual == expected);
}

TEST_CASE("XOBoard::full returns false if even just one cell of the board is empty")
{
	auto actual = Game::XOBoard(3, 3, { 1, 1, 1, 0, 1, 1, 1, 1, 1 }).full();
	auto expected = false;
	CHECK(actual == expected);
}