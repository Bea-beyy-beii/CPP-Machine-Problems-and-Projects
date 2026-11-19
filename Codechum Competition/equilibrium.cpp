//an equilibrium number is a number in an array where the sum of the elements to the right and left are equal

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int size;
	cout << "Enter the size of the array: ";
	cin >> size;

	vector <int> nums(size);

	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < size; i++) {
		int leftSum = 0, rightSum = 0;

		for (int j = 0; j < i; j++) {
			leftSum += nums[j];
		}

		for (int k = size - 1; k > i; k--) {
			rightSum += nums[k];
		}

		if (leftSum == rightSum) {
			cout << "Equilibrium number: " << nums[i];
			return 0;
		}
	}
	cout << "No equilibrium number found.";
}