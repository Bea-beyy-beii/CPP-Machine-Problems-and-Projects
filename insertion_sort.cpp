#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& nums, int length) {
	for (int i = 1; i < length; i++) {
		int key = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			j = j - 1;
		}
		nums[j + 1] = key;
	}
}

int main() {

	int length;
	cout << "Enter how many numbers you want to sort: ";
	cin >> length;

	vector <int> nums(length);

	cout << "Enter the specific numbers separated by a space: ";
	for (int i = 0; i < length; i++) {
		cin >> nums[i];
	}

	insertion_sort(nums, length);

	cout << "\nSorted Array:\n";
	for (int i = 0; i < length; i++) {
		cout << "nums[" << i << "] = " << nums[i] << endl;
		//printf("nums[%d] = %d\n", i, nums[i]);
	}

	return 0;
}