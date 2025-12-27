#include "PhoneBook.h" 
#include <iostream>
#include <limits>

using namespace std;

// Function Definitions

void addContact(Schema& db) {
    // FIX: Change 'string' to 'std::string' to avoid confusion with mysqlx::string
    std::string name, phone;

    // ... clear buffer code if needed ...
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Phone: ";
    getline(cin, phone);

    Table contacts = db.getTable("contacts");
    contacts.insert("name", "phone").values(name, phone).execute();
    cout << "--> Success! Contact saved.\n";
}

void viewContacts(Schema& db) {
    Table contacts = db.getTable("contacts");
    RowResult res = contacts.select("id", "name", "phone").execute();

    cout << "\n--- SAVED CONTACTS ---\n";
    for (Row row : res) {
        cout << row[0] << "\t" << row[1] << "\t" << row[2] << endl;
    }
}