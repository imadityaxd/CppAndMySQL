THIS FILE ACTS AS READEME FOR THE PhoneBook DIRECTORY
It contains information about this mini-project.
It also contains instructions on how to compile and run the project.

README - 

# 📞 Console PhoneBook Application

A robust C++ console application that performs CRUD operations on a MySQL database using the modern **X DevAPI**. This project demonstrates secure database connectivity, method chaining, and proper C++ project structure.

## 🚀 Features
- **Add Contact:** Securely insert names and phone numbers into the database.
- **View Contacts:** Fetch and display formatted records from MySQL.
- **Input Validation:** Handles buffer clearing and multi-word input (e.g., full names).
- **Modern Architecture:** Uses MySQL X Protocol (Port 33060).

## 🛠️ Tech Stack
- **Language:** C++ (C++17 standard or higher recommended)
- **Database:** MySQL 8.0+
- **Library:** MySQL Connector/C++ 9.5 (X DevAPI)
- **IDE:** Visual Studio 2022

## ⚙️ Prerequisites
Before running this project, ensure you have:
1.  **MySQL Server** installed and running.
2.  **MySQL Connector/C++ 9.5** installed.
3.  **Visual Studio** with "Desktop development with C++" workload.

## 💾 Database Setup
Run the following SQL script in MySQL Workbench to prepare the database:

```sql
CREATE DATABASE phonebook_db;
USE phonebook_db;

CREATE TABLE contacts (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    phone VARCHAR(20),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

🔧 Installation & Configuration (Visual Studio)
Clone/Download this repository.

Open the Solution (.sln) in Visual Studio.

Configure Paths (If they differ on your machine):

Project Properties -> C/C++ -> General -> Additional Include Directories: C:\Program Files\MySQL\MySQL Connector C++ 9.5\include

Project Properties -> Linker -> General -> Additional Library Directories: C:\Program Files\MySQL\MySQL Connector C++ 9.5\lib64\vs14

Project Properties -> Linker -> Input -> Additional Dependencies: mysqlcppconnx.lib

DLL Setup:

Copy mysqlcppconnx-9-vs14.dll from the MySQL installation folder.

Paste it into the x64/Release folder inside your project directory.

⚠️ Critical Troubleshooting
"Read Access Violation" or Crash on Startup?

Ensure Visual Studio is set to Release mode (not Debug).

The MySQL Connector libraries are pre-compiled in Release mode; mixing them with a Debug application causes memory conflicts.

🤝 Contribution
Feel free to fork this project and add "Update" or "Delete" functionality!