// this program checks if an array is a palindrome (applicable to strings as well)
// core logic: loop through the array by starting with i and ending with n/2
// then compare [i] with [n-1-i]

#include <cstdio>
#include <cmath> 
using namespace std;

int main() {
    long long num_floats, order, parade[100000] = {};
    bool symmetrical = true;
    scanf("%lld", &num_floats);

    if (num_floats < 1 || num_floats > pow(10, 5)) {
        return 0;
    }

    parade[num_floats];
    for (int i = 0; i < num_floats; i++) {
        scanf("%lld", &parade[i]);

        if (parade[i] < 1 || parade[i] > pow(10, 9)) {
            return 0;
        }
    }

    for (int i = 0; i < num_floats / 2; i++) {
        if (parade[i] != parade[num_floats - 1 - i]) {
            symmetrical = false;
            break;
        }
    }

    if (symmetrical) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}