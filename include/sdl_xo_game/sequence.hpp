#pragma once

namespace Game
{
	template<class T>
	struct __declspec(novtable) Sequence
	{
		virtual ~Sequence() = default;
		virtual T vector() const = 0;
	};
}