# Bank Management System

This project is a simple console-based Bank Management System implemented in C++. It provides basic functionalities for managing customer accounts, including account creation, deposits, withdrawals, balance inquiries, account modifications, and more.

## Features

- **Create New Account**: Allows a user to create a new bank account.
- **Deposit Amount**: Facilitates depositing money into a user's account.
- **Withdraw Amount**: Enables a user to withdraw money from their account.
- **Balance Inquiry**: Displays the current balance in a user's account.
- **Close Account**: Allows a user to close their account.
- **Transfer Cash**: Facilitates transferring money between accounts.
- **Modify Account**: Enables a user to update their account details.
- **Loan Facility**: Provides a feature to grant loans to customers.
- **Manager Access**: A special manager login to view the bank's total vault and customer details.

## Structure

- **Manager**: A struct with manager credentials (`manid` and `pinnn`).
- **Node (Linked List)**: A struct representing a customer account in a linked list. Each node holds details such as ATM number, PIN, balance, and other personal details.
- **Functions**: Various functions are implemented to handle operations like creating accounts, processing transactions, account modifications, and manager-specific tasks.

## Usage

- **Manager Login**: Press 'a' to enter the manager section.
- **Customer Options**: Press 'b' to access customer-related functionalities such as creating an account, depositing, withdrawing, etc.
- **Main Menu**: Use the menu to navigate between different banking operations.

## Requirements

- **Compiler**: Ensure you have a C++ compiler that supports `iostream`, `conio.h`, and other standard libraries.
- **Platform**: The program uses `#include <Windows.h>`, making it platform-dependent (Windows OS).

## Note

- The program is designed for educational purposes and may not be suitable for production without modifications and enhancements.
- The user interface is text-based, running entirely in a console window.

## Authors

- **Umair Munir**
- **Qirab Hassan**
- **Omar Ikram**

---

**💻 Keep coding, keep improving—every line you write brings you closer to mastering the craft. 🚀**
