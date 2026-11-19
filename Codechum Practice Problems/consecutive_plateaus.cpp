//CONSECUTIVE PLATEAUS
//a plateau is a group of 2 or more equal numbers that appear next to each other in a sequence
//count how many plateaus there are (input ends with 0, values must be from 1 to 1000)

#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	vector <int> sequence;
	printf("Enter sequence: ");

	//read numbers until 0 is entered
	int i;
	while (true) {
		scanf("%d", &i);

		if (i == 0) break; //0 marks the end of the sequence

		if (i < 0 || i > 1000) return 0; //invalid input, stop the program

		sequence.push_back(i);
	}

	//group consecutive equal numbers together as {number, how many times in a row}
	int count = 1;
	vector <pair<int, int>> pairing;//use vector pairs because hash maps do not preserve groups and order (violates tc 4)
	for (int i = 1; i < sequence.size(); i++) {//start at index 1 to avoid errors in i-1 if i is 0
		if (sequence[i] == sequence[i - 1]) {
			count++; //same as previous number, group keeps growing
		}
		else {
			pairing.push_back({ sequence[i - 1], count }); //group ended, save it
			count = 1; //start counting a new group
		}
	}

	pairing.push_back({ sequence.back(), count }); //add last group; pairs are only pushed when conditions break

	//count the groups that have a length of 2 or more (those are the plateaus)
	int counter = 0;
	for (auto& pair : pairing) {
		if (pair.second > 1) {
			counter++; //checks if groups appear more than once
		}
	}
	printf("Plateau count: %d", counter);

	/*
	for this type of problem where order and groupings matter,
	hash maps would not work because they do not preserve order and groupings.

	in the instance of tc 4 (if pattern breaks, start counting again), you need to have a vector pair
	that will store the groups and how many times a specific number appeared.
	*/
}
