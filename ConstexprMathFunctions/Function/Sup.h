// ☕ Привет
#pragma once

#include <iostream>

#include "Constant.h"
#include "../Common/Common.h"

namespace ConstexprMathFunctions
{
	namespace Function
	{
		// F1(F2(x))
		template <class F1, class F2>
		class Sup
		{
		public:
			static constexpr double f(double x)
			{
				return F1::f(F2::f(x));
			}

			using Derivative = F1;

			static constexpr bool GetIdenticallyValue()
			{
				if constexpr (F1::IdenticallyValue)
				{
					return F1::IdenticallyValue;
				}
				return F1::f(F2::IdenticallyValue);
			}

			static constexpr bool HasIdenticallyValue = F1::HasIdenticallyValue || F2::HasIdenticallyValue;
			static constexpr int  IdenticallyValue = GetIdenticallyValue();

			static constexpr bool HasSum = false;

			static void Print()
			{
				if (HasIdenticallyValue)
				{
					std::cout << IdenticallyValue;
					return;
				}
				if constexpr (Common::IsIdenticallyZero<F1>())
				{
					F2::Print();
				}
				else if constexpr (Common::IsIdenticallyZero<F2>())
				{
					F1::Print();
				}
				else
				{
					//std::cout << "(";
					F1::Print();
					std::cout << " + ";
					F2::Print();
					//std::cout << ")";
				}
			}
		};
	}
}