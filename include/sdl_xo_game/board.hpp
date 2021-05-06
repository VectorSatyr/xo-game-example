#pragma once
#include <cstddef>

namespace Game
{
	struct __declspec(novtable) Board
	{
		virtual ~Board() = default;
		virtual std::size_t lines(std::size_t value, std::size_t length) const = 0;
		virtual void place(std::size_t value, std::size_t x, std::size_t y) = 0;
		virtual bool full() const = 0;
	};
}