// this program calculates the sum of the inner and outer elements of a square matrix
// the logic is that the outer elements are the first and last rows and columns (0 and size-1), 
// while the inner elements are the rest of the elements in the matrix

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int size;
	cout << "Enter the size of the matrix:";
	cin >> size;

	vector <vector<int>> Matrix(size, vector<int>(size));

	int inner = 0, outer = 0;

	cout << "Enter the elements of the matrix: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> Matrix[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((i == 0 || i == size - 1) || (j == 0 || j == size - 1)) {
				outer += Matrix[i][j];
			}
			else {
				inner += Matrix[i][j];
			}
		}
	}

	cout << "Outer sum: " << outer << endl;
	cout << "Inner sum: " << inner;
}