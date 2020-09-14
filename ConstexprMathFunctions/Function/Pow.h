// ☕ Привет
#pragma once

#include <iostream>

#include "Constant.h"
#include "../Common/Common.h"

namespace ConstexprMathFunctions
{
	namespace Function
	{
		template <int Exp>
		class Pow
		{
		public:
			static constexpr double f(double x)
			{
				return pow(x, Exp);
			}

			// "Показатель вперед, на степень ниже"
			using Derivative = Mul<Constant<Exp>, Pow<Exp - 1>>;

			static constexpr bool HasIdenticallyValue = (Exp == 0);
			static constexpr int  IdenticallyValue = 1;

			static void Print()
			{
				if constexpr (Exp == 0)
				{
					std::cout << "0";
				}
				else if constexpr (Exp == 1)
				{
					std::cout << "x";
				}
				else
				{
					std::cout << "x^" << Exp;
				}
			}
		};
	}
}