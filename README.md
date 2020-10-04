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

Примеры использования:
Т.к. все операции происходят на этапе компиляции, то будем оперировать типами (используя using).
Хотим создать функцию `f(x) = x*x + 3*(2 + x)`. Делается это так:
```cpp
using SqrX = Mul<X, X>;
using Xplus2mul3 = Mul< Constant<3>, Sum<Constant<2>, X> >;

using F = Sum<SqrX, Xplus2mul3>;
```

Итого имеем **тип** F, у которого есть static constexpr функция f(double x). 
Можем на **этапе компиляции** это проверить: `static_assert(F::f(2) == 16, "Incorrect value");`

Можем взять новый тип, который будет представлять *производную* этой функции.
`using DerF = F::Derivative;`. Она равна `2*x + 3`

Аналогично можно проверить значение производной: `static_assert(DerF::f(2) == 7, "Incorrect value");`

Брать производные можно бесконечно.

Также функцию можно вывести на экран. У всех функций есть статический метод Print();
Например, для
```cpp
std::cout << "  f(x) = ";       F::Print(); std::cout << std::endl;
std::cout << " f'(x) = ";    DerF::Print(); std::cout << std::endl;
std::cout << "f''(x) = "; DerDerF::Print(); std::cout << std::endl;
```

Будет выведено:
```
  f(x) = x*x + 3*(2 + x)
 f'(x) = x + x + 3
f''(x) = 2
```
