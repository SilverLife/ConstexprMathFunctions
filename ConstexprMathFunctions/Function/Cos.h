// ☕ Привет
#pragma once

#include <iostream>

#include "Constant.h"
#include "X.h"
#include "../Common/Common.h"

namespace ConstexprMathFunctions
{
	namespace Function
	{
		constexpr int Fact(int n)
		{
			int res = 1;
			for (int i = 2; i <= n; i++)
			{
				res *= i;
			}
			return res;
		}

		constexpr double ConstexprPow(double x, int n)
		{
			double res = 1;
			for (int i = 1; i <= n; i++)
			{
				res *= x;
			}
			return res;
		}

		constexpr double ConstexprCos(double x, int n = 12)
		{
			double res = 1;
			int sign = -1;
			for (int i = 2; i < n; i += 2)
			{
				res += sign * ConstexprPow(x, i) / Fact(i);
				sign *= -1;
			}
			return res;
		}

		template <class Arg>
		class Sin;

		template <class Arg = X>
		class Cos
		{
		public:
			static constexpr double f(double x)
			{
				return ConstexprCos(Arg::f(x));
			}

			using Derivative = typename Mul<Sin<Arg>, typename Arg::Derivative>;;

			static constexpr bool HasIdenticallyValue = Arg::HasIdenticallyValue;
			static constexpr double  IdenticallyValue = ConstexprCos(Arg::IdenticallyValue);

			static constexpr bool HasSum = false;


			static void Print()
			{
				if constexpr (HasIdenticallyValue)
				{
					std::cout << IdenticallyValue;
				}
				else
				{
					std::cout << "cos(";
					Arg::Print();
					std::cout << ")";
				}
			}
		};
	}
}