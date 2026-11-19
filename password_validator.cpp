#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool hasUpper, hasLower, hasDigit, hasPunct, hasNoSpace = true;

int main() {

    string p;
    bool valid;

    do {
        cout << "Enter Password: ";
        cin >> p;

        valid = p.length() >= 8 &&
            any_of(p.begin(), p.end(), ::isupper) &&
            any_of(p.begin(), p.end(), ::islower) &&
            any_of(p.begin(), p.end(), ::isdigit) &&
            any_of(p.begin(), p.end(), ::ispunct) &&
            none_of(p.begin(), p.end(), ::isspace);

        cout << (valid ? "Password Accepted" : "Weak Password\n") << endl;
    } while (!valid);

    return 0;

    /* PLAN 2
    for (char c : p) {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
        if (isdigit(c)) hasDigit = true;
        if (ispunct(c)) hasPunct = true;
        if (isspace(c)) hasNoSpace = false;
    }

    cout << (p.length() >= 8 && hasUpper && hasLower && hasDigit && hasPunct && hasNoSpace ? "Password Accepted" : "weak password") << endl;

    */

}