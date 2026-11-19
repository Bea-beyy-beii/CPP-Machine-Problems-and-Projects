#include <iostream> 
using namespace std;

int main() {
    char line[100];
    cin.getline(line, 100);

    char binary[8];
    int length = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ') {
            if (length >= 8) {
                cout << "Invalid";
                return 0;
            }
            binary[length] = line[i];
            length++;
        }
    }

    if (length == 0) {
        cout << "Invalid";
        return 0;
    }

    int decimal = 0;
    for (int i = 0; i < length; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            cout << "Invalid";
            return 0;
        }
        decimal = decimal * 2 + (binary[i] - '0');
    }

    cout << decimal << endl;
    return 0;
}