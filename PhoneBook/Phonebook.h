#pragma once // Prevents the file from being included twice
#include <mysqlx/xdevapi.h>
#include <string>

// We declare the namespace here so we can use it in arguments
using namespace mysqlx;

// Function Declarations (Prototypes)
// We just say "These exist", we don't write the code yet.
void addContact(Schema& db);
void viewContacts(Schema& db); 
