//MINIMAL SUBARRAY LENGTH
//find the minimal length of a subarray whose sum is greater than or equal to the target
//print 0 if no such subarray exists

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, target;
	cout << "Enter array size and target sum: ";
	cin >> n >> target;

	vector <int> elements(n);

	cout << "Enter array elements: ";
	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}

	//sliding window technique: right expands the window, left shrinks it
	int sum = 0, left = 0;
	int minLen = 10000; 

	for (int right = 0; right < n; right++) {
		sum += elements[right]; //add the new element to the window

		//while the window meets the target, record its length then shrink it from the left
		while (sum >= target) {
			minLen = min(minLen, right - left + 1);
			sum -= elements[left];
			left++;
		}
	}

	//minLen never changed, so no subarray reached the target
	if (minLen == 10000) {
		cout << "Minimal length: 0";
	}
	else {
		cout << "Minimal length: " << minLen;
	}

}
