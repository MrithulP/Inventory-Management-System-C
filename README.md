# Simple Inventory Management System

A menu-driven console application written in C that allows a user to manage product records in a store. All data is stored in memory for the duration of the program session.

---

## Features

| # | Operation | Algorithm / Technique |
|---|-----------|----------------------|
| 1 | Add Product | Array insertion |
| 2 | Display All Products | Formatted table output |
| 3 | Search Product | Linear Search |
| 4 | Delete Product | Element shift after removal |
| 5 | Sort by Price | Selection Sort (ascending) |
| 6 | Sort by Quantity | Insertion Sort (ascending) |
| 7 | Exit | — |

---

## Data Structure

Each product record contains:

- **Product ID** — unique integer identifier
- **Product Name** — string (up to 49 characters)
- **Price** — floating-point value
- **Quantity** — integer stock count

All records are held in a fixed-size **array of structures** (`MAX_PRODUCTS = 100`).

---

## Concepts Demonstrated

| Concept | Usage in Project |
|---------|-----------------|
| Arrays | Store multiple product records |
| Structures (`struct`) | Define the product data format |
| Linear Search | Search product by ID (O(n)) |
| Selection Sort | Sort by price — finds the minimum in each pass |
| Insertion Sort | Sort by quantity — builds a sorted sub-array incrementally |
| Functions | Modular design — one function per operation |
| Menu-driven Program | Loop-based user interaction via `switch-case` |

---

## Getting Started

### Prerequisites

A C compiler such as **GCC** (comes pre-installed on Linux/macOS; use [MinGW](https://www.mingw-w64.org/) on Windows).

### Compile

```bash
gcc -Wall -o inventory inventory.c
```

### Run

```bash
./inventory          # Linux / macOS
inventory.exe        # Windows
```

---

## Usage

On launch the main menu is displayed:

```
============================================================
          SIMPLE INVENTORY MANAGEMENT SYSTEM
============================================================
  1. Add Product
  2. Display All Products
  3. Search Product (by ID)
  4. Delete Product (by ID)
  5. Sort by Price    [Selection Sort]
  6. Sort by Quantity [Insertion Sort]
  7. Exit
------------------------------------------------------------
  Enter your choice:
```

Enter a number (1–7) to perform the corresponding operation. The menu repeats until you choose **7 (Exit)**.

### Example Session

```
Enter your choice: 1

--- Add New Product ---
Enter Product ID   : 101
Enter Product Name : Apple Juice
Enter Price        : 45.50
Enter Quantity     : 30

[✓] Product added successfully! (Total products: 1)
```

```
Enter your choice: 2

--- Inventory List (1 products) ---
------------------------------------------------------------
| ID     | Name                 | Price      | Qty      |
------------------------------------------------------------
| 101    | Apple Juice          | 45.50      | 30       |
------------------------------------------------------------
```

---

## Project Structure

```
inventory.c       ← single-file source; all logic contained here
```

### Function Overview

| Function | Description |
|----------|-------------|
| `addProduct()` | Reads product details from stdin and appends to the array |
| `displayProducts()` | Prints all products in a formatted table |
| `searchProduct()` | Prompts for an ID and performs a linear search |
| `deleteProduct()` | Removes a product by ID and shifts remaining elements left |
| `sortByPrice()` | Sorts the array in-place by price using Selection Sort |
| `sortByQuantity()` | Sorts the array in-place by quantity using Insertion Sort |
| `printLine()` | Helper — prints a table divider |
| `printHeader()` | Helper — prints the table column header |
| `printProduct()` | Helper — prints one product row |
| `showMenu()` | Displays the main menu |
| `main()` | Entry point; drives the menu loop |

---

## Limitations

- **No persistence** — all data is lost when the program exits.
- **Fixed capacity** — maximum of 100 products (defined by `MAX_PRODUCTS`).
- **No duplicate ID check** — the same ID can be added more than once.
- **No edit/update** — to change a product, delete it and re-add.

---

## Possible Enhancements

- **File handling** — save and load data from a CSV or binary file for persistence.
- **Linked list** — replace the fixed array with a dynamically allocated linked list to remove the size limit.
- **Update product** — add an option to edit an existing record in place.
- **Duplicate ID validation** — reject additions where the ID already exists.
- **Inventory value report** — calculate and display the total value (`price × quantity`) across all products.

---

## License

This project is released for educational purposes.
