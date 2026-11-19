#include <iostream>
using namespace std;

int main() {
	int searchArr[5] = {};
	cout << "Enter 5 numbers spearated by space: ";

	for (int i = 0; i < 5; i++) {
		cin >> searchArr[i];
	}

	int choice;
	cout << "Enter a number from the list: ";
	cin >> choice;

	for (int i = 0; i < 5; i++) {
		if (choice == searchArr[i]) {
			cout << choice << " is in position " << i + 1;
		}
	}
}