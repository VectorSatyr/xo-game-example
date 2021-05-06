#pragma once
#include <cstddef>

namespace game
{
	struct __declspec(novtable) board
	{
		virtual ~board() = default;
		virtual std::size_t lines(std::size_t value, std::size_t length) const = 0;
		virtual void place(std::size_t value, std::size_t index) = 0;
		virtual bool full() const = 0;
	};
}