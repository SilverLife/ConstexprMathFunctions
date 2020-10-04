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
