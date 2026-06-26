#pragma once
#include <map>
#include <string>
using namespace std;

//This manages grocery item counts, the file operations, and menu functions.
class GroceryTracker {
private:
	// This stores each grocery item and the number of times it was purchased.
	std::map<std::string, int> itemFrequency;
	std::string inputFileName;
	std::string backupFileName;

	// This is the internal functions used to control the tracker.
	bool loadItemsFromFile();
	bool createrBackupFile() const;
	void displayMenu() const;
	int getMenuChoice() const;
	void searchForItem() const;
	void printFrequencyList() const;
	void printHistogram() const;
	std::string formatItemName(const std::string& itemName) const;

public:
	GroceryTracker();
	void runProgram();
};
