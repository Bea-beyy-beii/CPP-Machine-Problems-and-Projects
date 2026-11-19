#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string hex;
    cin >> hex;
    bool isValid = true;
    for (size_t i = 0; i < hex.length(); i++) {
        char ch = hex[i];
        if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))) {
            isValid = false;
            break;
        }
    }
    if (!isValid) {
        cout
            << "Invalid" << endl;
        return 0;
    }
    for (size_t i = 0; i < hex.length(); i++) {
        char ch = hex[i];
        int decimal = 0;
        if (ch >= '0' && ch <= '9') {
            decimal = ch - '0';
        }
        else if (ch >= 'A' && ch <= 'F') {
            decimal = ch - 'A' + 10;
        }
        else if (ch >= 'a' && ch <= 'f') {
            decimal = ch - 'a' + 10;
        }
        for (int bit = 3; bit >= 0; bit--) {
            int powerOf2 = 1;
            for (int j = 0; j < bit; j++) {
                powerOf2
                    = powerOf2 * 2;
            }
            if (decimal >= powerOf2) {
                cout
                    << "1";
                decimal
                    = decimal - powerOf2;
            }
            else {
                cout
            }
        }
    }
    cout << endl;
    return 0;
}