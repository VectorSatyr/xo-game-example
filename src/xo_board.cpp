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
		using size_type = typename std::vector<std::size_t>::size_type;
		std::vector<std::vector<std::size_t>> lines;

		// acquire line(s)
		switch (length) {
		case 0:
			// do nothing
			break;

		case 1:
			for (auto cell : cells) lines.push_back({ cell });
			break;

		default:
			const auto size(cells.size()),
				w(width - length + 1),
				h(height - length + 1);

			for (size_type y = 0; y < height; ++y) {
				for (size_type x = 0; x < width; ++x) {
					const auto n = (y * width) + x;
					if (x < w && y < h) {
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
					if (x < w) {
						lines.push_back(
							Game::Discriminate<std::size_t>(
								cells, length, [&n](const size_type s) {
									return n + s;
								}).vector());
					}
					if (y < h) {
						lines.push_back(
							Game::Discriminate<std::size_t>(
								cells, length, [this, &n](const size_type s) {
									return n + (s * width);
								}).vector());
					}
				}
			}
		}

		// test matches(s)
		std::size_t total = 0;
		const auto pred = [&value](const std::size_t n) noexcept {
			return (n == value);
		};
		for (const auto& line : lines) {
			if (std::count_if(
				line.cbegin(), line.cend(), pred) == length) {
				total++;
			}
		}

		// finished
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