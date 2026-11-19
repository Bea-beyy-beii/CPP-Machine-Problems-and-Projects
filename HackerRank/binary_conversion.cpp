#include <iostream> 
using namespace std;

int main() {
    int binaryNum[32];
    int digit;
    cin >> digit;

    if (digit <= 0 || digit >= 256) {
        cout << "Invalid";
        return 0;
    }

    int i = 0;
    while (digit > 0) {
        binaryNum[i] = digit % 2;
        digit = digit / 2;
        i++;
    }
    for (int k = 0; k < 8 - i; k++) {
        cout << 0;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
    cout << endl;
}