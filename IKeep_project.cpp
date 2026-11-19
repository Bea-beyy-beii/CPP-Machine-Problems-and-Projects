/*
	IKEEP - ACCOUNT RECORD KEEPER

	a console program that keeps track of account names, passwords, and the date
	each password was last updated. records are saved as .txt files inside:
		<user folder>/Documents/Ikeep/Data

	MODULE 1: FILE SET UP     - choose an existing record file or create a new one
	MODULE 2: ADD ACCOUNT     - save a new account, password, and date
	MODULE 3: UPDATE ACCOUNT  - change an account's password (the date becomes today)
	MODULE 4: REMOVE ACCOUNT  - delete an account from the file
	MODULE 5: VIEW ACCOUNT    - search for an account and show its password and
								how many days have passed since it was last updated

	each line in a record file looks like this: account password YYYY-MM-DD
	because the parts are separated by spaces, account names and passwords cannot contain spaces

	note: passwords are saved as plain text, so this is not a secure storage
*/

#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <sstream>
#include <ctime>
#include <limits>

//HELPER FUNCTIONS

//gets the user's home folder (USERPROFILE on Windows, HOME on other systems)
static std::string getUserFolder() {
#ifdef _WIN32
	char* user = nullptr;
	size_t len = 0;
	if (_dupenv_s(&user, &len, "USERPROFILE") == 0 && user != nullptr) {
		std::string folder(user);
		free(user); //_dupenv_s allocates memory, so it has to be freed
		return folder;
	}
	return "."; //fallback: current folder
#else
	const char* home = std::getenv("HOME");
	return home ? home : ".";
#endif
}

//converts a time into local date/time (localtime_s for Visual Studio, localtime_r for others)
static std::tm getLocalTime(std::time_t t) {
	std::tm result = {};
#ifdef _WIN32
	localtime_s(&result, &t);
#else
	localtime_r(&t, &result);
#endif
	return result;
}

//returns today's date as YYYY-MM-DD
static std::string getTodayDate() {
	std::tm localTime = getLocalTime(std::time(nullptr));
	std::ostringstream dateStream;
	dateStream << std::put_time(&localTime, "%Y-%m-%d");
	return dateStream.str();
}

//reads a YYYY-MM-DD string into tm, returns false if the format is wrong
static bool parseDate(const std::string& dateString, std::tm& tm) {
	tm = {};
	std::istringstream ss(dateString);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail()) return false;

	char extra;
	if (ss >> extra) return false; //there are extra characters after the date

	tm.tm_isdst = -1; //let mktime figure out daylight saving time
	return true;
}

//returns how many days have passed since the given date, or -1 if the date is invalid
static int calculateDaysSince(const std::string& dateString) {
	std::tm tm;
	if (!parseDate(dateString, tm)) return -1;

	std::time_t lastUpdate = std::mktime(&tm);
	std::time_t now = std::time(nullptr);

	return static_cast<int>(std::difftime(now, lastUpdate) / (60 * 60 * 24));
}

//reads a whole line and returns its first non-space character ('\0' if the line is empty)
static char readChar() {
	std::string input;
	std::getline(std::cin, input);
	for (char c : input) {
		if (c != ' ' && c != '\t') return c;
	}
	return '\0';
}

//reads a number for list selections, returns 0 (an invalid selection) if the input is not a number
static size_t readSelection() {
	size_t number;
	if (!(std::cin >> number)) {
		std::cin.clear(); //reset cin so it can be used again after bad input
		number = 0;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return number;
}

//checks if a string has a space or tab (spaces would break how lines are saved)
static bool hasSpace(const std::string& s) {
	return s.find_first_of(" \t") != std::string::npos;
}

//loads all non-empty lines (one account per line) from the record file
static std::vector<std::string> loadAccounts(const std::filesystem::path& path) {
	std::vector<std::string> accounts;
	std::ifstream inFile(path);
	std::string line;
	while (std::getline(inFile, line)) {
		if (!line.empty())
			accounts.push_back(line);
	}
	return accounts;
}

//rewrites the whole record file with the given accounts
static void saveAccounts(const std::filesystem::path& path, const std::vector<std::string>& accounts) {
	std::ofstream outFile(path, std::ios::trunc);
	for (const auto& accLine : accounts) {
		outFile << accLine << std::endl;
	}
}

//prints the accounts as a numbered list (name and last updated date only, no passwords)
static void printAccountList(const std::vector<std::string>& accounts) {
	for (size_t i = 0; i < accounts.size(); ++i) {
		std::istringstream ss(accounts[i]);
		std::string acc, pass, date;
		ss >> acc >> pass >> date;

		std::cout << i + 1 << ". "
			<< acc << " (Last updated: "
			<< date << ")\n";
	}
}

int main() {
	//MODULE 1: FILE SET UP

	std::string initialPath = getUserFolder() + "/Documents/Ikeep/Data";
	std::filesystem::create_directories(initialPath);

	std::string name;
	if (!std::filesystem::is_empty(initialPath)) {
		std::cout << "These are all the files you can check from:" << std::endl;
		for (const auto& entry : std::filesystem::directory_iterator(initialPath)) {
			std::cout << entry.path().filename().string() << std::endl;
		}
		std::cout << "\nType the name of the file to access, to add another, just type a new name instead!";
		std::cout << "\n(type the name but dont include \".txt\"): ";
	}
	else {
		std::cout << "Name a new file so we can start keeping account records!: ";
	}

	//keep asking until a name is entered
	std::getline(std::cin, name);
	while (name.empty()) {
		std::cout << "File name cannot be empty, try again: ";
		std::getline(std::cin, name);
	}

	//remove ".txt" if the user typed it anyway, so it doesn't become "name.txt.txt"
	if (name.size() > 4 && name.substr(name.size() - 4) == ".txt") {
		name = name.substr(0, name.size() - 4);
	}

	std::filesystem::path path = std::filesystem::path(initialPath) / (name + ".txt");

	//create the file if it doesn't exist yet (append mode never erases existing records)
	{
		std::ofstream file(path, std::ios::app);
		if (!file.is_open()) {
			std::cerr << "Couldn't open file";
			return 0;
		}
	}

	//CHOICES FOR MODULE 2, 3, 4 AND 5

	std::cout << "\nWhat would you like to do for now?\n(1 for add, 2 for update, 3 for remove, 4 for view, 0 to terminate): ";
	char choices = readChar();

	while (choices != '0') {

		//MODULE 2 (ADD ACCOUNT)
		if (choices == '1') {

			std::cout << "\nDo you want to add an account? (y/n): ";
			char confirm = readChar();

			if (confirm == 'y' || confirm == 'Y') {

				std::string account, password, date;
				std::cout << "\nEnter account name: ";
				std::getline(std::cin, account);

				std::cout << "Enter password: ";
				std::getline(std::cin, password);

				std::cout << "Enter date (YYYY-MM-DD): ";
				std::getline(std::cin, date);

				//check if the account name already exists in the file
				bool exists = false;
				for (const auto& line : loadAccounts(path)) {
					std::istringstream ss(line);
					std::string acc;
					ss >> acc;
					if (acc == account) {
						exists = true;
						break;
					}
				}

				std::tm dateCheck;
				if (account.empty() || password.empty() || date.empty()) {
					std::cout << "Invalid input. Fields cannot be empty.\n";
				}
				else if (hasSpace(account) || hasSpace(password)) {
					std::cout << "Invalid input. Account name and password cannot contain spaces.\n";
				}
				else if (!parseDate(date, dateCheck)) {
					std::cout << "Invalid date. Please use the format YYYY-MM-DD.\n";
				}
				else if (calculateDaysSince(date) < 0) {
					std::cout << "Invalid date. The date cannot be in the future.\n";
				}
				else if (exists) {
					std::cout << "That account already exists. Use update (2) to change its password.\n";
				}
				else {
					std::ofstream file(path, std::ios::app);
					file << account << " "
						<< password << " "
						<< date << std::endl;

					std::cout << "Account added successfully.\n";
				}
			}
		}

		//MODULE 3 (UPDATE ACCOUNT)
		else if (choices == '2') {

			std::cout << "\nDo you want to update an account? (y/n): ";
			char confirm = readChar();

			if (confirm == 'y' || confirm == 'Y') {

				std::vector<std::string> accounts = loadAccounts(path);

				if (accounts.empty()) {
					std::cout << "No accounts available to update.\n";
				}
				else {
					std::cout << "\nSelect account number to update:\n";
					printAccountList(accounts);

					std::cout << "Enter number: ";
					size_t updateIndex = readSelection();

					if (updateIndex == 0 || updateIndex > accounts.size()) {
						std::cout << "Invalid selection.\n";
					}
					else {
						std::string newPassword;
						std::cout << "Enter new password: ";
						std::getline(std::cin, newPassword);

						if (newPassword.empty()) {
							std::cout << "Password cannot be empty.\n";
						}
						else if (hasSpace(newPassword)) {
							std::cout << "Password cannot contain spaces.\n";
						}
						else {
							//get the account name from the selected line
							std::istringstream ss(accounts[updateIndex - 1]);
							std::string acc;
							ss >> acc;

							//replace with the new password and today's date
							accounts[updateIndex - 1] = acc + " " + newPassword + " " + getTodayDate();

							//rewrite the entire file with the updated list
							saveAccounts(path, accounts);

							std::cout << "Account updated successfully.\n";
						}
					}
				}
			}
		}

		//MODULE 4 (REMOVE ACCOUNT)
		else if (choices == '3') {

			std::cout << "\nDo you want to remove an account? (y/n): ";
			char confirm = readChar();

			if (confirm == 'y' || confirm == 'Y') {

				std::vector<std::string> accounts = loadAccounts(path);

				if (accounts.empty()) {
					std::cout << "No accounts available to remove.\n";
				}
				else {
					std::cout << "\nSelect account number to remove:\n";
					printAccountList(accounts);

					std::cout << "Enter number: ";
					size_t removeIndex = readSelection();

					if (removeIndex == 0 || removeIndex > accounts.size()) {
						std::cout << "Invalid selection.\n";
					}
					else {
						std::cout << "Remove this account? (y/n): ";
						char finalConfirm = readChar();

						if (finalConfirm == 'y' || finalConfirm == 'Y') {
							//remove the selected line, then rewrite the file without it
							accounts.erase(accounts.begin() + (removeIndex - 1));
							saveAccounts(path, accounts);

							std::cout << "Account removed successfully.\n";
						}
					}
				}
			}
		}

		//MODULE 5 (VIEW ACCOUNT)
		else if (choices == '4') {

			std::cout << "Do you want to view your accounts? (Y/N): ";
			char viewChoice = readChar();

			while (viewChoice == 'Y' || viewChoice == 'y') {

				std::string account;
				std::cout << "\nSearch Account: ";
				std::getline(std::cin, account);

				if (account.empty()) {
					std::cout << "No account entered.\n";
				}
				else {
					std::ifstream inFile(path);

					if (!inFile) {
						std::cout << "Error opening file.\n";
						break;
					}

					std::string line;
					bool found = false;

					// READ FILE LINE BY LINE
					while (std::getline(inFile, line)) {

						std::istringstream iss(line);
						std::string fileAccount, filePassword, fileDate;

						// PARSE EACH LINE
						if (iss >> fileAccount >> filePassword >> fileDate) {

							if (fileAccount == account) {
								found = true;

								// CALCULATE DAYS SINCE LAST UPDATE
								int daysSinceUpdate = calculateDaysSince(fileDate);

								// DISPLAY DETAILS
								std::cout << std::endl << std::left << std::setw(30) << "ACCOUNT" << std::setw(30) << "|| PASSWORD" << "|| DAYS SINCE LAST UPDATE\n";
								std::cout << std::left << std::setw(30) << fileAccount << "|| "
									<< std::left << std::setw(27) << filePassword << "|| ";

								if (daysSinceUpdate < 0)
									std::cout << "unknown (invalid date saved)\n";
								else
									std::cout << daysSinceUpdate << "\n";
								break;
							}
						}
					}
					if (!found) {
						std::cout << "Account not found.\n";
					}
				}

				std::cout << "\nDo you want to view again? (Y/N): ";
				viewChoice = readChar();
			}
		}

		//any other input
		else {
			std::cout << "Invalid choice.\n";
		}

		//redirection to other options
		std::cout << "\nDo you want to choose other options?\n(1 for add, 2 for update, 3 for remove, 4 for view, 0 to terminate): ";
		choices = readChar();
	}

	//termination
	return 0;
}
