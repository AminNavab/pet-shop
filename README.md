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

`