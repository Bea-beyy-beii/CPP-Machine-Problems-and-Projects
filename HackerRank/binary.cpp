#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string binary;
    cin >> binary;
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++) {
        char ch = binary[i];
        if (ch != '0' && ch != '1') {
            cout<< "Invalid";
            return 0;
        }
        decimal = decimal * 2;
        if (ch == '1') {
            decimal = decimal + 1;
        }
    }
    cout << decimal << endl
    return 0;
}