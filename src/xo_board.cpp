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
		const std::size_t size(width * height);
		std::size_t total(0), count(0);

		// south-east line
		for (std::size_t n = 0; n < size; n += (width + 1)) {
			if (cells[n] == value) count++;
		}
		if (count == length) total++;
		count = 0;

		// south-west line
		for (auto n = width - 1; n < size - 1; n += (width - 1)) {
			if (cells[n] == value) count++;
		}
		if (count == length) total++;
		count = 0;

		// rows
		const auto pred = [&value](const std::size_t n) noexcept {
			return n == value;
		};
		for (auto it = cells.cbegin();
			it != cells.cend();
			it += width) {
			if (std::count_if(it, it + width, pred) == length) {
				total++;
			}
		}

		// columns
		std::vector<std::size_t> columns;
		for (std::size_t n = 0; n < size; n++) {
			columns.push_back(cells[(n * width) % (size - 1)]);
		}
		for (auto it = columns.cbegin();
			it != columns.cend();
			it += width) {
			if (std::count_if(it, it + width, pred) == length) {
				total++;
			}
		}
		return total;
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