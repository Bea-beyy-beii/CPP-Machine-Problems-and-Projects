// this practice activity accepts number inputs,
// calculates total, counts entries, and identifies the largest and smallest numbers entered
// then optionally saves the inputs to a txt file and displays the contents of the file in the console

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	int number;
	char choice;
	int total = 0, count = 0, max = 0, min = 100;

	do {
		cout << "Enter a number: ";
		cin >> number;

		while (number <= 0 || number > 100) {
			cout << "Numbers must be between 1-100.\nEnter a new number: ";
			cin >> number;
		}

		total += number;
		count++;

		if (number > max) {
			max = number;
		}

		if (number < min) {
			min = number;
		}

		cout << "\nDo you want to enter more numbers? Enter Y/N: ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	string fileName;
	cout << "\nEnter file name to save data: ";
	cin >> fileName;

	ofstream myFile;
	myFile.open(fileName);
	if (!myFile) {
		do {
			cout << "Error creating file.\nEnter new file name: ";
			cin >> fileName;

			myFile.clear();
			myFile.open(fileName);
		} while (!myFile);
	}

	double average = static_cast <double> (total) / count;

	myFile << "Sum of Entries: " << total << endl;
	myFile << "Number of Entries: " << count << endl;
	myFile << fixed << setprecision(2) << "Average: " << average << endl;
	myFile << "Largest Number: " << max << endl;
	myFile << "Smallest Number: " << min << endl;

	myFile.close();

	char view;
	cout << "Do you want to view the data in the console? Enter Y/N: ";
	cin >> view;

	if (view == 'Y' || view == 'y') {
		ifstream inFile;
		inFile.open(fileName);

		if (!inFile) {
			cout << "Error opening file." << endl;
		}

		string line;
		while (getline(inFile, line)) {
			cout << line << endl;
		}

		/*
		while (!inFile.eof()) {
			string line;
			getline(inFile, line);
			cout << line << endl;
		}
		*/

		inFile.close();
	}
	return 0;
}

