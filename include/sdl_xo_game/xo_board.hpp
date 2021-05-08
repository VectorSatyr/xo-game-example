#pragma once
#include "sdl_xo_game/board.hpp"
#include <vector>

namespace Game
{
	class XOBoard final :
		public Board
	{
	public:
		XOBoard(std::size_t width, std::size_t height);
		XOBoard(std::size_t width, std::size_t height, std::vector<std::size_t> cells);
		std::size_t lines(std::size_t value, std::size_t length) const override;
		void place(std::size_t value, std::size_t x, std::size_t y) override;
		bool full() const override;
	private:
		const std::size_t width, height;
		std::vector<std::size_t> cells;
	};
}