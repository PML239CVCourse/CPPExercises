#include "some_math.h"
#include <bits/stdc++.h>

int fibbonachiRecursive(int n) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);


    int x;
    for (int i = 2; i < n+1; i++) {
        x = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(x);
    }

    return fib[n];
}

int fibbonachiFast(int n) {
    // TODO 04 реализуйте быструю функцию Фибоначчи с использованием std::vector
    return 0;
}

double solveLinearAXB(double a, double b) {
    // TODO 10 решите линейное уравнение a*x+b=0 а если решения нет - верните наибольшее значение double - найдите как это сделать в интернете по запросу "so cpp double max value" (so = stackoverflow = сайт где часто можно найти ответы на такие простые запросы), главное НЕ КОПИРУЙТЕ ПРОСТО ЧИСЛО, ПОЖАЛУЙСТААаа
    // если решений сколь угодно много - верните максимальное значение со знаком минус
    double x = 0.0;
    return x;
}

std::vector<double> solveSquare(double a, double b, double c) {
    // TODO 20 решите квадратное уравнение вида a*x^2+b*x+c=0
    // если корня два - они должны быть упорядочены по возрастанию
    std::vector<double> results;
    // чтобы добавить в вектор элемент - нужно вызвать у него метод push_back:
    results.push_back(23.9);
    return results;
}
