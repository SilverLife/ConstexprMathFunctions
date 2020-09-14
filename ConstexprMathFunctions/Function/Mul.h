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
		class Mul
		{
		public:
			static constexpr double f(double x)
			{
				return F1::f(x) * F2::f(x);
			}

			using Derivative = Sum<typename Mul<typename F1::Derivative, typename F2>, typename Mul<typename F1, typename F2::Derivative> >;

			static constexpr bool GetHasIdenticallyValue()
			{
				if constexpr (F1::HasIdenticallyValue && F1::IdenticallyValue == 0)
				{
					return true;
				}
				else if constexpr (F2::HasIdenticallyValue && F2::IdenticallyValue == 0)
				{
					return true;
				}
				else if constexpr (F1::HasIdenticallyValue && F2::HasIdenticallyValue)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			static constexpr bool HasIdenticallyValue = GetHasIdenticallyValue();
			static constexpr int  IdenticallyValue = F1::IdenticallyValue * F2::IdenticallyValue;

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
				if (Common::IsIdenticallyOne<F1>())
				{
					F2::Print();
				}
				else if (Common::IsIdenticallyOne<F2>())
				{
					F1::Print();
				}
				else
				{
					std::cout << "(";
					F1::Print();
					std::cout << " * ";
					F2::Print();
					std::cout << ")";
				}
			}
		};

	}
}