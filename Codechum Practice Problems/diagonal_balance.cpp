//DIAGONAL BALANCE
//given an n x n grid, check if the main diagonal sum and the anti diagonal sum are equal
//if equal, print "-1 -1"
//if not, find one row (R) or column (C) to flip (multiply by -1) that would make both diagonal sums equal
//if no single row or column works, print "IMPOSSIBLE"

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cout << "Enter row and col: ";
	cin >> n;


	vector <vector<int>> matrix(n, vector <int>(n));
	cout << "Enter the grid: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	//compute both diagonal sums
	int main = 0, anti = 0;

	for (int i = 0; i < n; i++) {
		main += matrix[i][i];//do not use [i][j] unless you do checking i==j
		anti += matrix[i][n - 1 - i]; //anti diagonal goes from top right to bottom left
	}

	//already balanced, nothing to flip
	if (main == anti) {
		cout << "-1 -1";
		return 0;
	}

	//try flipping each row
	//flipping a value x changes the sum by -2x (remove x, then add -x)
	//row r touches the main diagonal at [r][r] and the anti diagonal at [r][n-1-r]
	for (int r = 0; r < n; r++) {
		int flipMain = main - 2 * matrix[r][r];
		int flipAnti = anti - 2 * matrix[r][n - 1 - r];

		if (flipMain == flipAnti) {
			cout << "R " << r;
			return 0;
		}
	}


	//try flipping each column
	//column c touches the main diagonal at [c][c] and the anti diagonal at [n-1-c][c]
	for (int c = 0; c < n; c++) {
		int flipMain = main - 2 * matrix[c][c];
		int flipAnti = anti - 2 * matrix[n - 1 - c][c];

		if (flipMain == flipAnti) {
			cout << "C " << c;
			return 0;
		}
	}

	//no single row or column flip can balance the diagonals
	cout << "IMPOSSIBLE";
}
