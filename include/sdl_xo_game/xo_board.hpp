#pragma once
#include "board.hpp"

namespace Game
{
	class XOBoard final :
		public Board
	{
	public:
		XOBoard(std::size_t width, std::size_t height);
		std::size_t lines(std::size_t value, std::size_t length) const override;
		void place(std::size_t value, std::size_t x, std::size_t y) override;
		bool full() const override;
	};
}