#include <iostream>
#include <string>
using namespace std;

int main() {
	string message;
	cout << "Enter the encoded message: ";
	getline(cin, message);

	string decodedMessage = "";
	for (int i = 0; i < message.length(); i++) {
		if (i % 3 == 0) {
			if (islower(message[i])) {
				decodedMessage += toupper(message[i]);
			}
			else {
				decodedMessage += message[i];
			}
		}
	}

	cout << "Decoded Message: " << decodedMessage;
}