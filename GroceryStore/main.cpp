#include<iostream>
#include "GroceryHeader.h"

using namespace std;

int main() {
	try {
		//Connect to the MySQL database
		Session sess("127.0.0.1", 33060, "root", "password");
		Schema db = sess.getSchema("grocery_db");
		while (true) {
			displayMenu();
			int choice;
			if (!(cin >> choice)) {
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			if (choice == 1) viewProducts(db);
			else if (choice == 2) buyProduct(db);
			else if (choice == 3) break;
			else cout << "Invalid choice!\n";
		}
	}
	catch (const std::exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}

void displayMenu() {
	cout << "\n=== xdCoder's Grocey ===\n";
	cout << "1. View Inventory\n";
	cout << "2. Buy Product\n";
	cout << "3. Exit\n";
	cout << "Enter Choice: ";
}