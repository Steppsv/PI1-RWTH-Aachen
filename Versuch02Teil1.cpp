//============================================================================
// Name        : Versuch02Teil1.cpp
// Author      : Stp
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n=20;
    std::cout << "Fibonacci f(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
