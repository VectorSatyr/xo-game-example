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
		std::size_t total = 0;

		if (length > 0) {
			const std::size_t size(cells.size());
			std::vector<std::vector<std::size_t>> lines;

			const auto w(width - length + 1);
			const auto h(height - length + 1);

			// south-east line(s)
			for (std::size_t y = 0; y < h; ++y) {
				for (std::size_t x = 0; x < w; ++x) {
					std::vector<std::size_t> line;
					for (std::size_t n = 0; n < length; ++n) {
						auto index = (y * width) + x + (n * (width + 1));
						if (index < size) line.push_back(cells.at(index));
					}
					if (line.size() == length) lines.push_back(line);
				}
			}

			// south-west line(s)
			for (std::size_t y = 0; y < h; ++y) {
				for (std::size_t x = 0; x < w; ++x) {
					std::vector<std::size_t> line;
					for (std::size_t n = 0; n < length; ++n) {
						auto index = (y * width) + (length - 1) + x + (n * (width - 1));
						if (index < size) line.push_back(cells.at(index));
					}
					if (line.size() == length) lines.push_back(line);
				}
			}

			// horizontal line(s)
			for (std::size_t y = 0; y < height; ++y) {
				for (std::size_t x = 0; x < w; ++x) {
					std::vector<std::size_t> line;
					for (std::size_t n = 0; n < length; ++n) {
						auto index = (y * width) + x + n;
						if (index < size) line.push_back(cells.at(index));
					}
					if (line.size() == length) lines.push_back(line);
				}
			}

			// vertical line(s)
			for (std::size_t y = 0; y < h; ++y) {
				for (std::size_t x = 0; x < width; ++x) {
					std::vector<std::size_t> line;
					for (std::size_t n = 0; n < length; ++n) {
						auto index = (y * width) + x + (n * width);
						if (index < size) line.push_back(cells.at(index));
					}
					if (line.size() == length) lines.push_back(line);
				}
			}

			// matches
			const auto pred = [&value](const std::size_t n) noexcept {
				return n == value;
			};
			for (const auto& line : lines) {
				if (std::all_of(line.cbegin(), line.cend(), pred)) total++;
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