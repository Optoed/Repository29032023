#include <iostream>
using namespace std;

void fib(int n) {

    int a1 = 0, a2 = 1, a3, i = 0;

    if (n == 0 || n == 1) {
        cout << a1 << endl;
    }

    else if (n == 2) {
        cout << a2 << endl;
    }

    else {
        while (i < n) {
            int a3 = a1 + a2;
            cout << a1 << endl;
            a1 = a2;
            a2 = a3;
            i++;
        }
    }
}



int main() {
	cout << "Hello, World!" << endl;

    setlocale(LC_ALL, "RUS");
    int n;
    cout << "n = ";
    cin >> n;
    cout << endl;

    fib(n);
}
