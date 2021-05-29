#include "sdl_xo_game/xo_board.hpp"
#include "sdl_xo_game/discriminate.hpp"
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
		std::size_t total = 0;

		// acquire line(s)
		if (length == 1) {
			total += std::count_if(cells.cbegin(), cells.cend(),
				[&value](const auto elem) { return (elem == value); });
		}
		else if (length > 1) {
			std::vector<std::vector<std::size_t>> lines;
			const auto size(cells.size());
			const size_type scan_width(width - length + 1),
				scan_height(height - length + 1);

			for (size_type y = 0; y < height; ++y) {
				for (size_type x = 0; x < width; ++x) {
					const auto n = (y * width) + x;
					if (x < scan_width && y < scan_height) {
						lines.push_back(
							Game::Discriminate<std::size_t>(
								cells, length, [this, &n](const size_type s) {
									return n + (s * (width + 1));
								}).vector());
						lines.push_back(
							Game::Discriminate<std::size_t>(
								cells, length,
								[this, &n, &length](const size_type s) {
									return n + (length - 1) + (s * (width - 1));
								}).vector());
					}
					if (x < scan_width) {
						lines.push_back(
							Game::Discriminate<std::size_t>(
								cells, length, [&n](const size_type s) {
									return n + s;
								}).vector());
					}
					if (y < scan_height) {
						lines.push_back(
							Game::Discriminate<std::size_t>(
								cells, length, [this, &n](const size_type s) {
									return n + (s * width);
								}).vector());
					}
				}
			}

			// test matches(s)
			auto pred([&value](auto elem) { return (elem == value); });
			total += std::count_if(lines.cbegin(), lines.cend(),
				[&length, &pred](const auto& line) {
					return (line.size() == length &&
						std::all_of(line.cbegin(), line.cend(), pred));
				});
		}

		// finished
		return total;
	}

	void XOBoard::place(std::size_t value, std::size_t x, std::size_t y)
	{
		cells[(y * width) + x] = value;
	}

	bool XOBoard::full() const
	{
		return std::all_of(
			cells.cbegin(), cells.cend(), 
			[](const std::size_t n) { return (n > 0); }
		);
	}
}