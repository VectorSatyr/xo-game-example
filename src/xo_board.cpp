#include "sdl_xo_game/xo_board.hpp"
#include <algorithm>

namespace Game
{
	XOBoard::XOBoard(std::size_t width, std::size_t height) :
		XOBoard(width, height, std::vector<std::size_t>(width * height, 0))
	{
	}

	XOBoard::XOBoard(
		std::size_t width, std::size_t height, std::vector<std::size_t> cells
	) :
		width(width), height(height), cells(cells)
	{
	}

	std::size_t XOBoard::lines(std::size_t value, std::size_t length) const
	{
		return 0;
	}

	void XOBoard::place(std::size_t value, std::size_t x, std::size_t y)
	{
	}

	bool XOBoard::full() const
	{
		return std::all_of(
			cells.cbegin(), cells.cend(), 
			[](const std::size_t n) { return (n > 0); }
		);
	}
}