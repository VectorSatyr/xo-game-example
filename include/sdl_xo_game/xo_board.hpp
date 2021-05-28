#pragma once
#include "sdl_xo_game/board.hpp"
#include <vector>

namespace Game
{
	class XOBoard final :
		public Board
	{
	private:
		using size_type = typename std::vector<std::size_t>::size_type;
	public:
		XOBoard(size_type width, size_type height);
		XOBoard(size_type width, size_type height, std::vector<std::size_t> cells);
		std::size_t lines(std::size_t value, std::size_t length) const override;
		void place(std::size_t value, std::size_t x, std::size_t y) override;
		bool full() const override;
	private:
		const size_type width, height;
		std::vector<std::size_t> cells;
	};
}