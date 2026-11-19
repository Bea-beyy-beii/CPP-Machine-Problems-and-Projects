#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    string fruit;

    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Invalid";
        return 0;
    }

    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, fruit);
        int total = 0;

        for (char c : fruit) {
            if (c == 'A') {
                total += 11;
            }
            else if (c == 'O') {
                total += 7;
            }
            else if (c == 'W') {
                total += 17;
            }
            else if (isspace(c)) {
                continue;
            }
            else {
                cout << "Invalid";
                return 0;
            }
        }
        cout << total << endl;
    }
    return 0;
}