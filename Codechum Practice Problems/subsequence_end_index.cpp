//SUBSEQUENCE END INDEX
//check if T is a subsequence of S (characters of T appear in S in the same order, not necessarily next to each other)
//print the index in S where the last character of T was matched, or -1 if T is not a subsequence

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string main, target;
	cout << "Enter main string S: ";
	cin >> main;
	cout << "Enter target string T: ";
	cin >> target;

	//two pointers: i walks through S, j walks through T
	int j = 0;           // pointer for p
	int lastIndex = -1;  // last matched index in s

	for (int i = 0; i < main.length(); i++) {
		if (main[i] == target[j]) {
			j++;           //move to the next character in T
			lastIndex = i; //remember where it was matched in S

			if (j == target.size()) break; //all of T was found, stop early
		}
	}

	if (j == target.size())
		cout << "Result: " << lastIndex;
	else
		cout << "Result: -1"; // not all chars found

}
