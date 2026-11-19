#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin
        >> n;
    if (n < 0) {
        cout
            << "Invalid";
        return 0;
    }
    if (n <= 1) {
        cout
            << n << " is not a prime number." << endl;
        return 0;
    }
    bool isPrime = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime
                break;
        }
    }
    if (isPrime) {
        cout
            = false;
        << n << " is a prime number." << endl;
    }
    else {
		cout << n << " is not a prime number." << endl;
    }
    return 0;
}