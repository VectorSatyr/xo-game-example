#include <doctest/doctest.h>
#include "sdl_xo_game/xo_board.hpp"

TEST_CASE("XOBoard::full returns true when all cells are occupied")
{
	auto actual = Game::XOBoard(3, 3, { 
		1, 1, 1, 
		1, 1, 1, 
		1, 1, 1 
	}).full();
	auto expected = true;
	REQUIRE(actual == expected);
}

TEST_CASE("XOBoard::full returns false when any cell is empty")
{
	auto actual = Game::XOBoard(3, 3, { 
		1, 1, 1, 
		0, 1, 1, 
		1, 1, 1 
	}).full();
	auto expected = false;
	REQUIRE(actual == expected);
}

TEST_CASE("XOBoard::lines returns total unique lines of value and length")
{
	auto actual = Game::XOBoard(3, 3, { 
		1, 1, 1, 
		1, 1, 0, 
		1, 0, 1
	}).lines(1, 3);
	auto expected = 4;
	REQUIRE(actual == expected);
}

TEST_CASE("XOBoard::lines returns 0 if length is 0")
{
	auto actual = Game::XOBoard(3, 3, {
		5, 5, 5,
		5, 5, 5,
		5, 5, 5
	}).lines(5, 0);
	auto expected = 0;
	REQUIRE(actual == expected);
}