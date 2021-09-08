#include <iostream> // таким образом подключаются системные библиотеки (эта нужна для вывода в консоль)
#include <vector> // подключаем библиотеку для поддержки вектора (массива динамического размера)

// таким образом подключаются наши функции
#include "simple_sum.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    /* // таким образом выводятся сообщения в консоль
     // std::cout = "standard console output" = поток информации в консоль
     // std::endl = "standard end of line" = конец строчки (то же что и "\n")
     std::cout << "Hello World!" << std::endl;

     int a = 10;
     std::cout << "Please enter b=";
     int b;
     std::cin >> b; // считываем из консоли переменную
     std::cout << "b=" << b << std::endl;

     // TODO 01 чтобы телепортироваться внутрь функции - попробуйте удерживая CTRL кликнуть мышкой по функции, например по sum (она засветится как портал)
     int res = sum(a, b);

     std::cout << "a+b=" << a << "+" << b << "=" << res << std::endl;

     // TODO 06 выведите в консоль чему равно fibbonachiFast(b), не забудьте что нужно добавить не хватающий инклюд - some_math.h в которой объявлена эта функция
     // std::cout << "fib(b)=" <<

     std::vector<double> values;
     std::cout << "values size: " << values.size() << std::endl;
     values.push_back(10);
     std::cout << "values size after push_back: " << values.size() << std::endl;
     values.push_back(20);
     values.push_back(35);
     values.push_back(4);
     std::cout << "values size after more push_back: " << values.size() << std::endl;

     // TODO 07 выведите в консоль каждый элемент из динамического массива
     for (int i = 0; i < values.size(); ++i) {
         double x = values[i];
     }

     // TODO 08 считывайте числа из консоли (и добавляйте их в вектор) до тех пор пока не будет введен ноль, после чего просуммируйте считанные числа и выведите сумму
     // while () {
     //     ...
     //     if (...) {
     //         break;
     //     }
     // }
 */ vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    int n;
    cin >> n;
    int x;
    for (int i = 2; i < n+1; i++) {
        x = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(x);
    }
    cout << fib[n];
    return 0;
}
