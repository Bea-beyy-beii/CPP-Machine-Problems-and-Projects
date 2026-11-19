#include <iostream>
using namespace std;

int main() {
	int cities, connections;
	bool airlines[100][100] = {};

	cin >> cities >> connections;

	if (cities < 1 || cities > 100 || connections != cities * cities) {
		cout << "Invalid";
		return 0;
	}

	for (int i = 0; i < connections; i++) {
		int from, to;
		bool val;

		cin >> from >> to >> val;

		if ((from < 0 || from >= cities) || (to < 0 || to >= cities) || (val != 0 && val != 1)) {
			cout << "Invalid";
			return 0;
		}

		airlines[from][to] = val;
	}

	for (int i = 0; i < cities; i++) {
		for (int j = 0; j < cities; j++) {
			if (airlines[i][j] == 0) {
				cout << "From City " << i << " to City " << j << endl;
			}
		}
	}
	return 0;
}