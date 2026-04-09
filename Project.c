/*
 * ============================================================
 *   Simple Inventory Management System
 *   Language  : C
 *   Concepts  : Arrays, Structures, Linear Search,
 *               Selection Sort, Insertion Sort, Functions
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------
   Constants
------------------------------------------ */
#define MAX_PRODUCTS 100
#define NAME_LEN     50

/* ------------------------------------------
   Data Structure
------------------------------------------ */
typedef struct {
    int    id;
    char   name[NAME_LEN];
    float  price;
    int    quantity;
} Product;

/* ------------------------------------------
   Global inventory array & counter
------------------------------------------ */
Product inventory[MAX_PRODUCTS];
int     count = 0;          /* number of products currently stored */

/* ------------------------------------------
   Helper – print a divider line
------------------------------------------ */
void printLine(void) {
    printf("------------------------------------------------------------\n");
}

/* ------------------------------------------
   Helper – print table header
------------------------------------------ */
void printHeader(void) {
    printLine();
    printf("| %-6s | %-20s | %-10s | %-8s |\n",
           "ID", "Name", "Price", "Qty");
    printLine();
}

/* ------------------------------------------
   Helper – print a single product row
------------------------------------------ */
void printProduct(const Product *p) {
    printf("| %-6d | %-20s | %-10.2f | %-8d |\n",
           p->id, p->name, p->price, p->quantity);
}

/* ------------------------------------------
   1. ADD PRODUCT
------------------------------------------ */
void addProduct(void) {
    if (count >= MAX_PRODUCTS) {
        printf("\n[!] Inventory is full. Cannot add more products.\n");
        return;
    }

    Product p;

    printf("\n--- Add New Product ---\n");
    printf("Enter Product ID   : ");
    scanf("%d", &p.id);
    getchar();                          /* consume leftover newline */

    printf("Enter Product Name : ");
    fgets(p.name, NAME_LEN, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';   /* strip trailing newline */

    printf("Enter Price        : ");
    scanf("%f", &p.price);

    printf("Enter Quantity     : ");
    scanf("%d", &p.quantity);

    inventory[count] = p;
    count++;

    printf("\n[?] Product added successfully! (Total products: %d)\n", count);
}

/* ------------------------------------------
   2. DISPLAY ALL PRODUCTS
------------------------------------------ */
void displayProducts(void) {
    if (count == 0) {
        printf("\n[!] No products in inventory.\n");
        return;
    }

    printf("\n--- Inventory List (%d products) ---\n", count);
    printHeader();
    for (int i = 0; i < count; i++) {
        printProduct(&inventory[i]);
    }
    printLine();
}

/* ------------------------------------------
   3. SEARCH PRODUCT  (Linear Search)
------------------------------------------ */
void searchProduct(void) {
    if (count == 0) {
        printf("\n[!] No products to search.\n");
        return;
    }

    int id;
    printf("\n--- Search Product ---\n");
    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("\n[?] Product found:\n");
            printHeader();
            printProduct(&inventory[i]);
            printLine();
            return;
        }
    }

    printf("\n[?] Product with ID %d not found.\n", id);
}

/* ------------------------------------------
   4. DELETE PRODUCT
------------------------------------------ */
void deleteProduct(void) {
    if (count == 0) {
        printf("\n[!] No products to delete.\n");
        return;
    }

    int id;
    printf("\n--- Delete Product ---\n");
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            /* Shift elements left to fill the gap */
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("\n[?] Product with ID %d deleted. (Total products: %d)\n",
                   id, count);
            return;
        }
    }

    printf("\n[?] Product with ID %d not found.\n", id);
}

/* ------------------------------------------
   5. SORT BY PRICE  (Selection Sort – ascending)
------------------------------------------ */
void sortByPrice(void) {
    if (count < 2) {
        printf("\n[!] Not enough products to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < count; j++) {
            if (inventory[j].price < inventory[minIdx].price) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Product temp     = inventory[i];
            inventory[i]     = inventory[minIdx];
            inventory[minIdx] = temp;
        }
    }

    printf("\n[?] Products sorted by price (ascending) using Selection Sort.\n");
    displayProducts();
}

/* ------------------------------------------
   6. SORT BY QUANTITY  (Insertion Sort – ascending)
------------------------------------------ */
void sortByQuantity(void) {
    if (count < 2) {
        printf("\n[!] Not enough products to sort.\n");
        return;
    }

    for (int i = 1; i < count; i++) {
        Product key = inventory[i];
        int j = i - 1;
        while (j >= 0 && inventory[j].quantity > key.quantity) {
            inventory[j + 1] = inventory[j];
            j--;
        }
        inventory[j + 1] = key;
    }

    printf("\n[?] Products sorted by quantity (ascending) using Insertion Sort.\n");
    displayProducts();
}

/* ------------------------------------------
   MENU
------------------------------------------ */
void showMenu(void) {
    printf("\n============================================================\n");
    printf("          SIMPLE INVENTORY MANAGEMENT SYSTEM\n");
    printf("============================================================\n");
    printf("  1. Add Product\n");
    printf("  2. Display All Products\n");
    printf("  3. Search Product (by ID)\n");
    printf("  4. Delete Product (by ID)\n");
    printf("  5. Sort by Price    [Selection Sort]\n");
    printf("  6. Sort by Quantity [Insertion Sort]\n");
    printf("  7. Exit\n");
    printf("------------------------------------------------------------\n");
    printf("  Enter your choice: ");
}

/* ------------------------------------------
   MAIN
------------------------------------------ */
int main(void) {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct();     break;
            case 2: displayProducts(); break;
            case 3: searchProduct();  break;
            case 4: deleteProduct();  break;
            case 5: sortByPrice();    break;
            case 6: sortByQuantity(); break;
            case 7:
                printf("\n[?] Exiting... Thank you!\n\n");
                break;
            default:
                printf("\n[!] Invalid choice. Please enter 1-7.\n");
        }

    } while (choice != 7);

    return 0;
}	
