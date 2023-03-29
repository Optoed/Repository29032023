#include <iostream>
using namespace std;

unsigned long long int fib(int n)
{
    if (n == 0 || n == 1)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}



int main() {
	cout << "Hello, World!" << endl;

    setlocale(LC_ALL, "RUS");
    int n;
    cout << "n = ";
    cin >> n;
    unsigned long long int x = fib(n);
    cout << "n-ый число Фибоначчи = " << x << endl;
}
