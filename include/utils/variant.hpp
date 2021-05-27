#pragma once
#include "sequence.hpp"
#include <functional>

namespace utils
{
	template<class T>
	class variant final : public sequence<T>
	{
	public:
		template<typename... Args>
		explicit variant(Args&&... args) :
			variant(std::function<std::vector<T>()>(
				[args...]() mutable -> std::vector<T> {
					return { std::forward<Args>(args)... };
				})) {};

		std::vector<T> vector() const override { return alloc(); };

	private:
		explicit variant(const std::function<std::vector<T>()> alloc) :
			alloc(alloc) {};

		const std::function<std::vector<T>()> alloc;
	};
}