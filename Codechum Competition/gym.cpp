#include <iostream>
using namespace std;

int main() {
	int base, months, miss;

	cout << "Enter the base score: ";
	cin >> base;
	cout << "Enter the number of months attended: ";
	cin >> months;
	cout << "Enter the number of absences: ";
	cin >> miss;

	int score = base + (months * 5) - (miss * 2);

	if (score >= 100) {
		cout << "Score: " << score << endl;
		cout << "Tier: Gold";
	}
	else if (score >= 50 && score <= 99) {
		cout << "Score: " << score << endl;
		cout << "Tier: Silver";
	}
	else {
		cout << "Score: " << score << endl;
		cout << "Tier: Bronze";
	}
}