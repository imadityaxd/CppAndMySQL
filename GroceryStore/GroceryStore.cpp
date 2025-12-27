#include "GroceryHeader.h"
#include <iostream>
#include <iomanip> //For std:setw (makes tables look nicer)

using namespace std;

void viewProducts(Schema& db) {
	Table products = db.getTable("products");
	RowResult res = products.select("id", "name", "price", "stock").execute();

	cout << "\n" << left
		<< setw(5) << "ID"
		<< setw(15) << "Name"
		<< setw(10) << "Price"
		<< setw(10) << "Stock" << endl;
	cout << "--------------------------------------------\n";
	for (Row row : res) {
		cout << left << setw(5) << row[0]
			<< setw(15) << row[1]
			<< setw(10) << row[2]
			<< setw(10) << row[3] << endl;
	}
}

//creating the buyProduct() function 
void buyProduct(Schema& db) {
    int id, qty;
    cout << "Enter Product ID: ";
    cin >> id;
    cout << "Enter Quantity: ";
    cin >> qty;

    Table products = db.getTable("products");

    // --- STEP 1: Find the Product ---
    // We need to know the Price and Current Stock before we can sell it.
    RowResult res = products.select("name", "price", "stock")
        .where("id = :id")
        .bind("id", id)
        .execute();

    // fetchOne() grabs the first row found. If no product matches the ID, it returns an empty row.
    Row row = res.fetchOne();

    // --- STEP 2: Validation (Does it exist?) ---
    if (!row) {
        cout << "❌ Error: Product ID " << id << " not found!\n";
        return; // Stop the function here
    }

    // Extract values safely from the database row
    // row[0] = name, row[1] = price, row[2] = stock
    std::string name = row[0].get<std::string>();
    double price = row[1].get<double>();
    int currentStock = row[2].get<int>();

    // --- STEP 3: Check Stock Levels ---
    if (qty > currentStock) {
        cout << "❌ Error: Not enough stock! Only " << currentStock << " left.\n";
        return;
    }

    // --- STEP 4: The Logic (Math) ---
    double totalBill = price * qty;
    int newStock = currentStock - qty;

    // --- STEP 5: UPDATE the Database ---
    // This is the new part! We overwrite the old 'stock' value with the new one.
    products.update()
        .set("stock", newStock)   // Set column 'stock' to variable newStock
        .where("id = :id")        // Only for this specific product ID
        .bind("id", id)
        .execute();

    // Success Message
    cout << "\n✅ PURCHASE SUCCESSFUL!\n";
    cout << "------------------------\n";
    cout << "Item:   " << name << endl;
    cout << "Qty:    " << qty << endl;
    cout << "Bill:   $" << totalBill << endl;
    cout << "------------------------\n";
}