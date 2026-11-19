
// this program compiles different tree patterns

#include <iostream>
using namespace std;

int main() {
    int lines;
    cin >> lines;

    // 1. inverted tree pattern
    for (int i = 0; i < lines; i++) {
        for (int j = i; j < lines; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // output:
    // *****
    // ****
    // ***
    // **
    // *


    // 2. right aligned tree pattern
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }

    // output:
    //     *
    //    **
    //   ***
    //  ****
    // *****


    // 3. left aligned tree pattern
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // output:
    // *
    // **
    // ***
    // ****
    // *****


    // 4. right aligned inverted tree pattern
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int k = i; k < lines; k++) {
            cout << "*";
        }
        cout << endl;
    }

    // output:
    // *****
    //  ****
    //   ***
    //    **
    //     *


    // 5. pyramid pattern
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k < (2 * i + 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // output:
    //     *
    //    ***
    //   *****
    //  *******
    // *********


    // 6. inverted pyramid pattern
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int k = 0; k < (2 * lines - 2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // output:
    // *********
    //  *******
    //   *****
    //    ***
    //     *


    // 7. diamond pattern

    // upper half
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k < (2 * i + 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // lower half
    for (int i = lines - 2; i >= 0; i--) {
        for (int j = 0; j < lines - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k < (2 * i + 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // output:
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    //  *******
    //   *****
    //    ***
    //     *

    return 0;
}