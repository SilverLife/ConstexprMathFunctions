// ☕ Привет
#pragma once

#include "AllFunctions.h"


namespace ConstexprMathFunctions
{
	using namespace Function;

	template <class F>
	void Print()
	{
		using    DerF = typename    F::Derivative;
		using DerDerF = typename DerF::Derivative;

		std::cout << "  f(x) = ";       F::Print(); std::cout << std::endl;
		std::cout << " f'(x) = ";    DerF::Print(); std::cout << std::endl;
		std::cout << "f''(x) = "; DerDerF::Print(); std::cout << std::endl;
	}

	void Test1()
	{
		// "Строим" на этапе компиляции функцию f(x) = x*x + 3*(2 + x)
		using SqrX = Mul<X, X>;
		using Xplus2mul3 = Mul< Constant<3>, Sum<Constant<2>, X> >;

		// F - это тип, у которого есть статическая constexpr функция f
		using F = Sum<SqrX, Xplus2mul3>;

		// Знаем на этапе компиляции, что f(2) == 12
		static_assert(F::f(2) == 16, "Incorrect value");


		// Возьмем производную этой функции
		// f'(x) = 2*x + 3
		using DerF = F::Derivative;

		// Знаем на этапе компиляции, что f'(2) == 7
		static_assert(DerF::f(2) == 7, "Incorrect value");

		// Возьмем вторую производную этой функции
		// f''(x) = 2
		using DerDerF = DerF::Derivative;

		// Знаем на этапе компиляции, что f'(2) == 7
		static_assert(DerDerF::f(2) == 2, "Incorrect value");

		// Знаем на этапе компиляции, что f''(x) === 2
		static_assert(DerDerF::HasIdenticallyValue, "DerDerF must be equal 2");
		static_assert(DerDerF::IdenticallyValue == 2, "DerDerF must be equal 2");

		// Ну а тут можно запустить прогу и посмотреть принты
		Print<F>();
	}

	void Test2()
	{
		// f(x) = x^4 + 3*x^3 + 5*x^2 + 3
		//using F = SumMany<Constant<3>, Constant<4>>::F;
		using F4 = Pow<4>;
		using F3 = MulConst<3, Pow<3>>;
		using F2 = MulConst<5, Pow<2>>;
		using F0 = Constant<3>;

		using F = Sum<F4, Sum<F3, Sum<F2, F0> > >;
		
		Print<F>();
	}

	void Test3()
	{
		using F = Sum<Constant<3>, Sum<Constant<4>, X>>;
		//using F = Mul<Constant<3>, Mul<Constant<3>, Pow<2>>>;

		F::Print();
		//F::Derivative::Print();
		//Print<F>();
	}

	void Test4()
	{
		// (3 + x)^2
		using Xplus3 = Sum<X, Constant<3>>;
		using F = Sup<Pow<2>, Xplus3>;

		F::Print();
	}
}