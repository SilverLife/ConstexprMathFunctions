// ☕ Привет
#pragma once

#include <iostream>

#include "Constant.h"
#include "../Common/Common.h"

namespace ConstexprMathFunctions
{
	namespace Function
	{
		template <class F1, class F2>
		class Sum
		{
		public:
			static constexpr double f(double x)
			{
				return F1::f(x) + F2::f(x);
			}

			using Derivative = Sum<typename F1::Derivative, typename F2::Derivative>;

			static constexpr bool HasIdenticallyValue = F1::HasIdenticallyValue && F2::HasIdenticallyValue;
			static constexpr double  IdenticallyValue    = F1::IdenticallyValue + F2::IdenticallyValue;

			static constexpr bool HasSum = !Common::IsIdenticallyZero<F1>() && !Common::IsIdenticallyZero<F2>();

			static void Print()
			{
				if (HasIdenticallyValue)
				{
					if (IdenticallyValue == 0)
					{
						return;
					}
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
