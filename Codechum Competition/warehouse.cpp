//each element in a matrix represents a warehouse cell
//the program will ask  how many actions will be performed
//the following n lines, it will ask for row, column, and action
//1 is to add 1, 2 is to deduct 1 if not empty (if 0, remain 0), and 3 is to clear that specific row

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int actions;
	cout << "Enter the number of actions: ";
	cin >> actions;

	vector <vector<int>> matrix(5, vector<int>(5, 0)); //all cells are initialized to 0

	int r, c, a;
	for (int i = 0; i < actions; i++) {
		cout << "Enter row, column, and action " << i + 1 << ": ";
		cin >> r >> c >> a;

		if (a == 1) {
			matrix[r][c] += 1;
		}
		else if (a == 2) {
			if (matrix[r][c] != 0) {
				matrix[r][c] -= 1;
			}
		}
		else if (a == 3) {
			for (int k = 0; k < 5; k++) {
				matrix[r][k] = 0;
			}
		}
		else {
			return 0;
		}

		for (int k = 0; k < 5; k++) {
			for (int l = 0; l < 5; l++) {
				cout << matrix[k][l] << " ";
			}
			cout << endl;
		}
	}

	int sum = 0;
	cout << "Final Matrix: " << endl;
	for (int k = 0; k < 5; k++) {
		for (int l = 0; l < 5; l++) {
			cout << matrix[k][l] << " ";
			sum += matrix[k][l];
		}
		cout << endl;
	}
	cout << "Total Inventory: " << sum;
}