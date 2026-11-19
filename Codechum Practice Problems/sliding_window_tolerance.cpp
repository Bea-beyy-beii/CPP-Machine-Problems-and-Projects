//SLIDING WINDOW TOLERANCE
//count how many windows of size w have (max - min) less than or equal to the tolerance t
//the data stream ends with -1

#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int w, t;
	printf("Enter window size and tolerance: ");
	scanf("%d %d", &w, &t);

	if (w < 2 || w > 100 || t < 0 || t > 1000000) return 0; //invalid input

	vector <int> stream;
	int num;

	//read numbers until -1 is entered
	printf("Enter data stream (end with -1): ");
	while (true) {
		scanf("%d", &num);

		if (num == -1) break; //end of stream
		if (num < 1 || num > 1000000) return 0; //invalid input

		stream.push_back(num);
	}


	int count = 0;

	//slide the window across the stream, i = start of the window
	for (int i = 0; i <= stream.size() - w; i++) {
		int max = 0, min = 1000000;

		//no complete window can be formed
		if (stream.size() < w) {
			count = 0;
			break;
		}

		//find the max and min inside the current window
		for (int j = i; j < i + w; j++) {

			if (stream[j] > max) {
				max = stream[j];
			}

			if (stream[j] < min) {
				min = stream[j];
			}
		}

		//window is valid if the difference is within the tolerance
		if (max - min <= t) {
			count++;
		}

	}

	printf("Valid Windows: %d", count);
}
