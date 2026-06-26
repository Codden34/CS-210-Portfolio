#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

// This sets the rquired input and backup filenames.
GroceryTracker::GroceryTracker() {
	inputFileName = "CS210_Project_Three_Input_File.txt";
	backupFileName = "frequency.dat";
}
bool GroceryTracker::loadItemsFromFile() {
	ifstream inputFile(inputFileName);
	string itemName;

	// This stops the loading process if the source file cannot be opened.
	if (!inputFile.is_open()) {
		cout << "Error: Unable to open " << inputFileName << "." << endl;
		return false;
	}
	// This clears the old data before loading the purchase records.
	itemFrequency.clear();
	// This counts each item as it is reads from the file.
	while (inputFile >> itemName) {
		itemFrequency[itemName]++;
	}
	inputFile.close();
	return true;
}
bool GroceryTracker::createrBackupFile() const {
	ofstream backupFile(backupFileName);

	// This saves every item and its final purchase count.
	if (!backupFile.is_open()) {
		cout << "Error: Unable to create " << backupFileName << "." << endl;
		return false;
	}
	for (const auto& item : itemFrequency) {
		backupFile << item.first << " " << item.second << endl;
	}
	backupFile.close();
	return true;
}
void GroceryTracker::displayMenu() const {
	cout << "n\Corner Grocer Item Tracker" << endl;
	cout << "____________________________" << endl;
	cout << "1. Search for an Item" << endl;
	cout << "2. Display all item frequencies" << endl;
	cout << "3. Display item histogram" << endl;
	cout << "4. Exit program" << endl;
	cout << "Enter your choice: ";
}
int GroceryTracker::getMenuChoice() const {
	int userChoice;

	// This keeps the requesting input until the user enters a vaild menu option.
	while (true) {
		displayMenu();

		if (cin >> userChoice && userChoice >= 1 && userChoice <= 4) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return userChoice;
		}
		cout << "\nInvalid choice. Enter a number from 1 to 4." << endl;
		
		// This resets the input stream before asking again.
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
string GroceryTracker::formatItemName(const string& itemName) const {
	string formattedName = itemName;

	if (formattedName.empty()) {
		return formattedName;
	}
	// This matches the capitalization used inside the input file.
	formattedName[0] = static_cast<char>(
		toupper(static_cast<unsigned char>(formattedName[0]))
		);
	for (size_t i = 1; i < formattedName.length(); ++i) {
		formattedName[i] = static_cast<char>(
			tolower(static_cast<unsigned char>(formattedName[i]))
			);
	}
	return formattedName;
}
void GroceryTracker::searchForItem() const {
	string itemName;
	
	cout << "\nEnter the item you wanted search for: ";
	getline(cin, itemName);

	// This formats the input before searching the map.
	itemName = formatItemName(itemName);
	auto itemPostition = itemFrequency.find(itemName);

	if (itemPostition != itemFrequency.end()) {
		cout << itemName << " were purchased "
			<< itemPostition->second << " times." << endl;
	}
	else {
		cout << itemName << " were purchased 0 times." << endl;
	}
}
void GroceryTracker::printFrequencyList() const {
	cout << "\nItem Purchase Frequencies" << endl;
	cout << "___________________________" << endl;

	// This Prints each grocery item beside its numeric count.
	for (const auto& item : itemFrequency) {
		cout << item.first << " " << item.second << endl;
	}
}
void GroceryTracker::printHistogram() const {
	cout << "\nItem Purchase Histogram" << endl;
	cout << "_________________________" << endl;

	// This prints one asterisk for every reacorded purchase.
	for (const auto& item : itemFrequency) {
		cout << item.first << " ";

		for (int count = 0; count < item.second; ++count) {
			cout << "*";
		}
		cout << endl;
	}
}
void GroceryTracker::runProgram() {
	// This loads the purchase records before opening the menu.
	if (!loadItemsFromFile()) {
		cout << "The program cannot continue without the input file." << endl;
		return;
	}
	// Ceate the required backup file automatically.
	if (!createrBackupFile()) {
		cout << "The Program cannot continue without the backup file." << endl;
		return;
	}
	int userChoice = 0;
	cout << "Corner Grocer purchase data loaded successfully." << endl;
	cout << backupFileName << " was created successfully." << endl;
	 //  This Keeps the program operational until the user selects exit.
	while (userChoice != 4) {
		userChoice = getMenuChoice();

		switch (userChoice) {
		case 1:
			searchForItem();
			break;

		case 2: 
			printFrequencyList();
			break;

		case 3:
			printHistogram();
			break;

		case 4: 
			cout << "\nCorner Grocer Item Tracker closed." << endl;
			break;
		}
	 }
}


