#pragma once
#include <mysqlx/xdevapi.h>
#include <string>

using namespace mysqlx;

// Function Prototypes
void displayMenu();
void viewProducts(Schema& db);
void buyProduct(Schema& db);
