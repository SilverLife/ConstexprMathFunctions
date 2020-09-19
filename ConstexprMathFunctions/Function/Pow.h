// ☕ Привет
#pragma once

#include <iostream>

#include "Constant.h"
#include "../Common/Common.h"

namespace ConstexprMathFunctions
{
	namespace Function
	{
		template <int Exp, class Arg = X>
		class Pow
		{
		public:
			static constexpr double f(double x)
			{
				return pow(Arg::f(x), Exp);
			}

			// "Показатель вперед, на степень ниже"
			// f(u)' = (u^n)' = n*u^(n-1)*u'
			using Derivative = Mul<Mul<Constant<Exp>, Pow<Exp - 1, Arg>>, typename Arg::Derivative>;

			static constexpr bool HasIdenticallyValue = (Exp == 0);
			static constexpr int  IdenticallyValue = 1;

			static constexpr bool HasSum = false;


			static void Print()
			{
				if constexpr (Exp == 0)
				{
					std::cout << "0";
				}
				else if constexpr (Exp == 1)
				{
					Arg::Print();
				}
				else if constexpr (!std::is_same_v<Arg, X>)
				{
					std::cout << "(";
					Arg::Print();
					std::cout << ")^" << Exp;
				}
				else
				{
					std::cout << "x^" << Exp;
				}
			}
		};
	}
}