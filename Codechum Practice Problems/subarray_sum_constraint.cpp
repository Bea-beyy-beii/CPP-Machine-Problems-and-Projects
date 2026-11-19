//SUBARRAY SUM CONSTRAINT
//count the number of subarrays that have a length of at least L and a sum that is at most S
//N = array size, S = max sum allowed, L = minimum subarray length

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int length, target, minLength;
	printf("Enter N, S, and L: ");
	scanf("%d %d %d", &length, &target, &minLength);

	//check the constraints, stop the program if invalid
	if (length < 1 || length > 100000 || target < 1 || target > pow(10, 18) || minLength < 1 || minLength > length) {
		return 0;
	}

	vector <int> nums(length);
	printf("Enter the array elements: ");
	for (int i = 0; i < length; i++) {
		scanf("%d", &nums[i]);
	}

	//i = start of the subarray, j = end of the subarray
	int count = 0;
	for (int i = 0; i < length; i++) {
		long long sum = 0;//change data type to handle test case 5 haha lol
		for (int j = i; j < length; j++) {
			sum += nums[j]; //extend the subarray by one element

			int sub = j - i + 1; //current subarray length

			if (sub >= minLength) {
				if (sum <= target) {
					count++; //valid subarray
				}
				else {
					break; //sum is already too big, extending further will not help
				}
			}
		}
	}
	printf("Count: %d", count);
}