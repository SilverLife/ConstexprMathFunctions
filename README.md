# ConstexprMathFunctions
Математические функции, у которых на этапе компиляции можно узнать значение и производную.
Список базовых функций:
```cpp
1. template <int Value> class Constant;          // f(x) = value
2. class X;                                      // f(x) = x
3. template <int Exp, class Arg = X> class Pow;  // f(x) = Arg(x)^Exp
4. template <class Arg = X> class Sin;           // f(x) = Sin(Arg(x))
5. template <class Arg = X> class Cos;           // f(x) = Cos(Arg(x))
```

Список комбинирующих функций:
```cpp
template <class F1, class F2> class Sum;         // f(x) = F1(x) + F2(x)
template <class F1, class F2> class Mul;         // f(x) = F1(x) * F2(x)
```

Примеры:
```cpp
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
```
