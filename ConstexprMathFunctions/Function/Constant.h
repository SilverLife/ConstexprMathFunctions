// ☕ Привет
#pragma once

#include <iostream>

namespace ConstexprMathFunctions
{
	namespace Function
	{
		template <int Value>
		class Constant
		{
		public:
			static constexpr double f(double x) { return Value; }
			static void Print() { std::cout << Value; }

			using Derivative = Constant<0>;

			// true, если данная функция тождественно равна числу
			static constexpr bool HasIdenticallyValue = true;
			static constexpr int  IdenticallyValue = Value;

			static constexpr bool HasSum = false;
		};
	}
}
