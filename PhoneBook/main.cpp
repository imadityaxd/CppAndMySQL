#include <iostream>
#include "PhoneBook.h" // Include your custom header

using namespace std;
using namespace mysqlx;

int main() {
    try {
        Session sess("127.0.0.1", 33060, "root", "password");
        Schema db = sess.getSchema("phonebook_db");

        // Your menu loop goes here...
        // When you need to do something, just call the function:
		
        viewContacts(db);

    }
    catch (const std::exception& e) {
        cout << e.what();
    }
    return 0;
}