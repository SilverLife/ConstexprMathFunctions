// ☕ Привет
#pragma once

namespace ConstexprMathFunctions
{
	namespace Common
	{
		template <class F>
		static constexpr bool IsIdenticallyZero()
		{
			return F::HasIdenticallyValue && (F::IdenticallyValue == 0);
		}

		template <class F>
		static constexpr bool IsIdenticallyOne()
		{
			return F::HasIdenticallyValue && (F::IdenticallyValue == 1);
		}

	}
}