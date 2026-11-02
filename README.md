<div align="center">

# Pet Shop Management System

**A C++ console application for managing pet shop products, customers, account balances, purchases, and order records.**

[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Storage](https://img.shields.io/badge/Storage-Binary%20Files-informational.svg)](#data-storage)
[![Application](https://img.shields.io/badge/Interface-Console-lightgrey.svg)](#usage-guide)

</div>

---

## Overview

Pet Shop Management System is a menu-driven application written in C++. It demonstrates how a small shop-management workflow can be implemented using classes, functions, conditional logic, file streams, and binary file storage.

The application provides two working modes:

- **Seller mode** — manage the product catalogue and view registered customers.
- **Customer mode** — browse and search products, add funds to an account, make purchases, and review personal orders.

Application records are stored locally in binary data files, allowing information to remain available between program runs.

> **Project scope:** This is a console-based educational project. It does not include a graphical interface, a database server, online payments, or password-based authentication.

## Features

### Seller

- Add a new product with a product number, name, category, and price.
- Prevent adding another product with an already-used product number.
- Display the product catalogue.
- Delete a product by its product number.
- Display the registered customer list.

### Customer

- Enter a customer number to access the customer workflow.
- Create a customer record when that number does not already exist.
- Display the customer's number, name, and account balance.
- Browse the product catalogue.
- Search for products by:
  - Product name
  - Product category
  - A minimum and maximum price range
- Increase the account balance.
- Purchase a product using its product number.
- Check whether the customer and product exist and whether the account balance covers the purchase.
- View the customer's order history.

### Local data persistence

The program reads and writes records using C++ file streams in binary mode. Product, customer, and order records are saved locally rather than being held only in memory.

## Technology Stack

| Technology | Purpose |
|---|---|
| C++ | Main programming language |
| Classes and objects | Represent products, customers, and orders |
| File streams (`ifstream`, `ofstream`, `fstream`) | Read and write persistent records |
| Binary file I/O | Store application records in local files |
| Standard Library | Console input/output, formatting, and string utilities |

The source uses C++ features compatible with a C++11-or-newer compiler.

## Repository Structure

```text
pet-shop/
├── main.cpp       # Program entry point and seller/customer menus
├── customers.h    # Customer records and account-balance operations
├── products.h     # Product records and catalogue operations
└── orders.h       # Purchase processing, order history, and product search
```

### Source file responsibilities

| File | Main responsibility |
|---|---|
| `main.cpp` | Starts the application, selects the user workflow, and dispatches menu actions |
| `customers.h` | Defines the `Customers` class and customer-related file operations |
| `products.h` | Defines the `Products` class and product catalogue operations |
| `orders.h` | Defines the `Orders` class, handles purchases and order history, and implements product search |

`main.cpp` includes `orders.h`, which in turn includes the customer and product headers.

## Requirements

To build and run the project, you need:

- A C++ compiler with C++11 support or newer.
- A terminal or command prompt.
- Git (optional, for cloning the repository).

Examples of suitable compilers include GCC, Clang, and Microsoft Visual C++.

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/AminNavab/pet-shop.git
```

### 2. Open the project directory

```bash
cd pet-shop
```

### 3. Compile

Using GCC or MinGW:

```bash
g++ -std=c++11 main.cpp -o pet-shop
```

Using Clang:

```bash
clang++ -std=c++11 main.cpp -o pet-shop
```

On Windows with MinGW, run the generated executable with:

```bash
pet-shop.exe
```

On Linux or macOS:

```bash
./pet-shop
```

If your compiler uses a different executable name or requires a platform-specific command, adjust the command accordingly.

## Usage Guide

After launching the program, it asks you to select a user workflow. The application then displays the corresponding menu.

### Seller workflow

Seller mode provides the following menu actions:

| Menu option | Action |
|---|---|
| 1 | Add a new product |
| 2 | Display all products |
| 3 | Delete a product by product number |
| 4 | Display all customers |
| 5 | Exit seller mode |

When adding a product, enter its product number, name, category, and price when prompted. Product numbers are checked against existing product records.

When deleting a product, enter the product number of the item to remove.

### Customer workflow

Customer mode first asks for a customer number.

- If the number is not already present in the customer data file, the program asks for a customer name and an initial account amount and creates a record.
- If the number already exists, the existing customer record is used.

The customer menu provides these actions:

| Menu option | Action |
|---|---|
| 1 | Display the product catalogue |
| 2 | Search for products |
| 3 | Increase the account balance |
| 4 | Purchase a product and display the customer's order history |
| 5 | Exit customer mode |

#### Searching for products

The search menu supports three criteria:

1. **Name** — find products whose stored name matches the entered name.
2. **Category** — find products in the entered category.
3. **Price range** — find products whose prices fall between the entered minimum and maximum values.

The current implementation uses exact text comparisons for name and category searches. Search terms should therefore match the stored text.

#### Adding account funds

Choose the balance-increase option and enter the amount to add when prompted. The updated customer record is written back to the customer data file.

#### Making a purchase

Choose the purchase option, review the product catalogue, and enter the product number to buy.

The application checks that:

- The customer record exists.
- The selected product exists.
- The customer's recorded balance is at least the product price.

If these checks pass, an order record is saved and the purchase amount is deducted from the customer's balance. The program then displays the customer's order history.

## Data Storage

The application uses local binary files. These files are created or updated when the corresponding operations are performed.

| File | Stored information |
|---|---|
| `products.dat` | Product records |
| `Customer.dat` | Customer records and account balances |
| `ordon.dat` | Purchase/order records |
| `newproducts.dat` | Temporary file used while deleting a product |

### Important notes

- Run the application from a directory where it can create and write these files.
- The data files are generated at runtime; they are not part of the source-code structure shown above.
- Keep the `.dat` files if you want to preserve the records between runs.
- Deleting these files removes the corresponding locally stored data.
- The current implementation uses binary representations of C++ objects. These files should be treated as application-specific data, not as portable interchange formats.

## How the Purchase Flow Works

At a high level, a customer purchase follows this sequence:

1. The customer selects the purchase option.
2. The product catalogue is displayed.
3. The customer enters a product number.
4. The application looks up the customer and product records.
5. It checks whether the account balance is sufficient.
6. If the checks pass, it appends an order record to `ordon.dat`.
7. The purchase amount is deducted from the customer's balance in `Customer.dat`.
8. The customer's order history is displayed.

If a required recor