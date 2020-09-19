// ☕ Привет
#pragma once

#include <iostream>

#include "Constant.h"
#include "X.h"
#include "Mul.h"
#include "Cos.h"
#include "../Common/Common.h"

namespace ConstexprMathFunctions
{
	namespace Function
	{
		


		constexpr double ConstexprSin(double x, int n = 12)
		{
			double res = x;
			int sign = -1;
			for (int i = 3; i < n; i += 2)
			{
				res += sign * ConstexprPow(x, i)/Fact(i);
				sign *= -1;
			}
			return res;
		}

		template <class Arg = X>
		class Sin
		{
		public:
			static constexpr double f(double x)
			{
				return ConstexprSin(Arg::f(x));
			}

			using Derivative = typename Mul<Cos<Arg>, typename Arg::Derivative>;

			static constexpr bool HasIdenticallyValue = Arg::HasIdenticallyValue;
			static constexpr double  IdenticallyValue = ConstexprSin(Arg::IdenticallyValue);

			static constexpr bool HasSum = false;


			static void Print()
			{
				if constexpr (HasIdenticallyValue)
				{
					std::cout << IdenticallyValue;
				}
				else 
				{
					std::cout << "sin(";
					Arg::Print();
					std::cout << ")";
				}
			}
		};
	}
}