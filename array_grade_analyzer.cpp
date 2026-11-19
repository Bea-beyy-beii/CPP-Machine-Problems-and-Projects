#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, max = 0, min = 100, passed = 0, fail = 0;
    double grades[1000] = {};
    double total = 0;

    cin >> n;

    while (n < 1 || n>1000) {
        cout << "Invalid. Enter a new number: ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cin >> grades[i];

        while (grades[i] < 60 || grades[i]>100) {
            cout << "Invalid grade. Enter again: ";
            cin >> grades[i];
        }

        if (grades[i] >= 75) {
            passed++;
        }
        else {
            fail++;
        }

        if (grades[i] > max) {
            max = grades[i];
        }

        if (grades[i] < min) {
            min = grades[i];
        }

        total += grades[i];

    }

    double average = total / n;
    average = (round(average * 100)) / 100;

    cout << "\nGrades: ";
    for (int j = 0; j < n; j++) {
        cout << grades[j] << " ";
    }

    cout << "\nAverage: " << average << endl;
    cout << "Highest Grade: " << max << endl;
    cout << "Lowest Grade: " << min << endl;
    cout << "Students Passed: " << passed << " out of " << n << endl;
    cout << "Students Failed: " << fail << " out of " << n << endl;

    return 0;
}