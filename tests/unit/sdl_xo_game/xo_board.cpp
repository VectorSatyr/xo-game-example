#include <doctest/doctest.h>
#include "sdl_xo_game/xo_board.hpp"

TEST_SUITE("Game::XOBoard")
{
	TEST_SUITE("Game::XOBoard::lines(value, length)")
	{
		TEST_CASE("Returns total unique lines of value and length")
		{
			auto actual = Game::XOBoard(3, 3, {
				1, 1, 1,
				1, 1, 0,
				1, 0, 1
				}).lines(1, 3);
			auto expected = 4;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns 0 if length is 0")
		{
			auto actual = Game::XOBoard(3, 3, {
				5, 5, 5,
				5, 5, 5,
				5, 5, 5
				}).lines(5, 0);
			auto expected = 0;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns 0 if no lines match value")
		{
			auto actual = Game::XOBoard(3, 3, {
				3, 3, 3,
				3, 3, 3,
				3, 3, 3
				}).lines(2, 1);
			auto expected = 0;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns 0 when length exceeds area")
		{
			auto actual = Game::XOBoard(3, 3, {
				7, 7, 7,
				7, 7, 7,
				7, 7, 7
				}).lines(7, 4);
			auto expected = 0;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns correct value when width exceeds length")
		{
			auto actual = Game::XOBoard(5, 3, {
				1, 1, 1, 1, 1,
				1, 0, 1, 1, 0,
				1, 1, 1, 1, 0
				}).lines(1, 3);
			auto expected = 11;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns correct value when height exceeds length")
		{
			auto actual = Game::XOBoard(3, 5, {
				0, 1, 1,
				1, 0, 1,
				1, 1, 0,
				1, 1, 1,
				1, 0, 1
				}).lines(1, 3);
			auto expected = 6;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns correctly when dimensions exceed length")
		{
			auto actual = Game::XOBoard(5, 5, {
				0, 1, 1, 0, 1,
				1, 0, 1, 0, 1,
				1, 1, 0, 1, 1,
				1, 1, 1, 0, 0,
				1, 0, 1, 0, 1
				}).lines(1, 2);
			auto expected = 25;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Only counts values once when length is 1")
		{
			auto actual = Game::XOBoard(3, 3, {
				0, 6, 6,
				6, 0, 6,
				6, 6, 0,
				}).lines(6, 1);
			auto expected = 6;
			REQUIRE(actual == expected);
		}
	}
	TEST_SUITE("Game::XOBoard::place(value, x, y)")
	{
		TEST_CASE("Puts a value on the board at the designated location")
		{
			Game::XOBoard xo(3, 3);
			xo.place(4, 1, 2);
			auto actual = xo.lines(4, 1);
			auto expected = 1;
			CHECK(actual == expected);
		}

		TEST_CASE("Does nothing when the designated location is occupied")
		{
			Game::XOBoard xo(3, 3, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			xo.place(10, 2, 1);
			auto actual = xo.lines(10, 1);
			auto expected = 0;
			CHECK(actual == expected);
		}

		TEST_CASE("Does nothing if the given location is out of bounds")
		{
			Game::XOBoard xo(2, 2, { 6, 6, 6, 6 });
			xo.place(7, 3, 3);
			auto actual = xo.lines(7, 1);
			auto expected = 0;
			CHECK(actual == expected);
		}
	}
	TEST_SUITE("Game::XOBoard::full()")
	{
		TEST_CASE("Returns true when all cells are occupied")
		{
			auto actual = Game::XOBoard(3, 3, {
				1, 1, 1,
				1, 1, 1,
				1, 1, 1
				}).full();
			auto expected = true;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns false when any cell is empty")
		{
			auto actual = Game::XOBoard(3, 3, {
				1, 1, 1,
				0, 1, 1,
				1, 1, 1
				}).full();
			auto expected = false;
			REQUIRE(actual == expected);
		}

		TEST_CASE("Returns false when there are no contents")
		{
			auto actual = Game::XOBoard(10, 10, {}).full();
			auto expected = false;
			REQUIRE(actual == expected);
		}
	}
}