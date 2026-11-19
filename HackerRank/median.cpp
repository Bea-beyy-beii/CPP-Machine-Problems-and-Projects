#include <iostream> 
#include <iomanip> 
using namespace std;

void insertion_sort(int arr[], int length);

int main() {
    int arr[15];
    int length = 0;
    int value;

    for (int i = 0; i < 15; i++) {
        cin >> value;

        if (value < 0) {
            cout << "Invalid";
            return 0;
        }

        if (value == 0) {
            break;
        }

        arr[length] = value;
        length++;
    }

    // If no valid numbers were entered 
    if (length == 0) {
        cout << "Invalid";
        return 0;
    }

    insertion_sort(arr, length);

    double median;

    if (length % 2 == 0) {
        median = (arr[length / 2 - 1] + arr[length / 2]) / 2.0;
    }
    else {
        median = arr[length / 2];
    }

    cout << fixed << setprecision(1) << median;

    return 0;
}

void insertion_sort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}