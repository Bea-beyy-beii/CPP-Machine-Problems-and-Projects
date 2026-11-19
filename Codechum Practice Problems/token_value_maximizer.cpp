//TOKEN VALUE MAXIMIZER
//divide the main string into tokens using the characters in the delimiter string,
//then print the token with the highest value
//scoring: digit = its own value, vowel = 2, consonant = 1, anything else = 0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string mainStr, delim;

	cout << "Enter the main string: ";
	cin >> mainStr;
	cin.ignore(); //clear the leftover newline before using getline

	cout << "Enter the delimiter string: ";
	getline(cin, delim);

	//replace every delimiter character with a space so it is easier to split
	for (char& c : mainStr) {
		if (delim.find(c) != string::npos) {
			c = ' ';
		}
	}

	//split the string into tokens by spaces
	vector <string> token;
	string sepWords = "";

	for (char c : mainStr) {
		if (c == ' ') {
			if (!sepWords.empty()) { //skip empty tokens (back to back delimiters)
				token.push_back(sepWords);
				sepWords = "";
			}
		}
		else {
			sepWords += c; //build the current token
		}
	}

	if (!sepWords.empty()) {
		token.push_back(sepWords); //add the last token since there is no space after it
	}

	//compute the value of each token and keep the highest one
	int maxSum = 0;
	string result = "";

	for (string s : token) {
		int sum = 0;
		for (char c : s) {
			if (isdigit(c)) {
				sum += c - '0'; //convert char digit to its int value
			}
			else if (isalpha(c)) {
				if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
					sum += 2; //vowel
				}
				else {
					sum += 1; //consonant
				}
			}
			else {
				sum += 0; //special characters have no value
			}
		}

		//strictly greater so the first token wins in case of a tie
		if (sum > maxSum) {
			maxSum = sum;
			result = s;
		}
	}
	cout << "Result: " << result;

}
