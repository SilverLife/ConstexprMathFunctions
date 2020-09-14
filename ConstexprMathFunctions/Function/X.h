// ☕ Привет
#pragma once

#include <iostream>

#include "Constant.h"

namespace ConstexprMathFunctions
{
	namespace Function
	{
		class X
		{
		public:
			static constexpr double f(double x) { return x; }
			static void Print() { std::cout << 'x'; }

			using Derivative = Constant<1>;

			static constexpr bool HasIdenticallyValue = false;
			static constexpr int  IdenticallyValue = 0;
		};
	}
}
