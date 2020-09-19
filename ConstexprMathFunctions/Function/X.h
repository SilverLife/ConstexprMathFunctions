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
			static void PrintL() { std::cout << '('; }
			static void PrintR() { std::cout << ')'; }

			using Derivative = Constant<1>;

			static constexpr bool HasIdenticallyValue = false;
			static constexpr int  IdenticallyValue = 0;

			static constexpr bool HasSum = false;
		};
	}
}
