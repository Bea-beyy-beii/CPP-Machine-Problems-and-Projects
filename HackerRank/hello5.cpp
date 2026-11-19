//this program reads a file containing a line of words, and a number
//it will then print that line n times, where n is the number read from the file

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	cout << "Program Started\n" << endl;

	/* option 1
	ifstream myFile("hello.txt");
	if (!myFile) {
		cout << "Error opening file" << endl;
		return 1;
	}

	string word;
	int num;
	getline(myFile, word);
	myFile >> num;

	myFile.close();

	*/

	string fileName;
	ifstream userFile;

	cout << "Enter the name of the file: ";
	cin >> fileName;

	userFile.open(fileName);

	if (!userFile) {
		do {
			cout << "\nError opening file" << endl;
			cout << "Enter a valid file name in the same path as the program: ";
			cin >> fileName;
			userFile.open(fileName);
		} while (!userFile);
	}

	string word;
	int num;

	getline(userFile, word);
	userFile >> num;

	userFile.close();

	cout << "\n";

	for (int i = 0; i < num; i++) {
		cout << word << endl;
	}

	return 0;
}