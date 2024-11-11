#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

int itemCodes[] = {101, 102, 103, 104, 105};
char itemNames[][MAX_NAME_LENGTH] = {"Apple", "Banana", "Orange", "Milk", "Bread"};
double itemPrices[] = {0.99, 0.59, 0.79, 1.29, 1.49};
int itemCount = 5; // number of items in the shop

int cartCodes[MAX_ITEMS];
int cartQuantities[MAX_ITEMS];
int cartCount = 0;

void displayMenu()
{
    printf("\nShopping Cart Menu:\n");
    printf("1. Add items to shopping cart\n");
    printf("2. Show current total\n");
    printf("3. Check out\n");
    printf("4. Cancel session\n");
    printf("q. Quit\n");
}

void displayItems()
{
    printf("\nAvailable items:\n");
    for (int i = 0; i < itemCount; i++)
    {
        printf("%d - %s - $%.2f\n", itemCodes[i], itemNames[i], itemPrices[i]);
    }
}

int addItemToCart()
{
    int code, quantity, found = 0;
    printf("\nEnter item code: ");
    scanf("%d", &code);

    for (int i = 0; i < itemCount; i++)
    {
        if (itemCodes[i] == code)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            cartCodes[cartCount] = code;
            cartQuantities[cartCount] = quantity;
            cartCount++;
            printf("%d x %s added to cart.\n", quantity, itemNames[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Invalid item code.\n");
    }
    return found;
}

void showCurrentTotal()
{
    double total = 0.0;
    for (int i = 0; i < cartCount; i++)
    {
        for (int j = 0; j < itemCount; j++)
        {
            if (cartCodes[i] == itemCodes[j])
            {
                total += itemPrices[j] * cartQuantities[i];
                break;
            }
        }
    }
    printf("Current total: $%.2f\n", total);
}

void checkout()
{
    double total = 0.0;
    printf("\nItemized Bill:\n");
    for (int i = 0; i < cartCount; i++)
    {
        for (int j = 0; j < itemCount; j++)
        {
            if (cartCodes[i] == itemCodes[j])
            {
                double itemTotal = itemPrices[j] * cartQuantities[i];
                printf("%d x %s - $%.2f\n", cartQuantities[i], itemNames[j], itemTotal);
                total += itemTotal;
                break;
            }
        }
    }
    printf("Total amount due: $%.2f\n", total);
}

void clearCart()
{
    cartCount = 0;
}

int confirmAction(const char *action)
{
    char confirm;
    printf("Are you sure you want to %s? (y/n): ", action);
    scanf(" %c", &confirm);
    return (confirm == 'y' || confirm == 'Y');
}

int main()
{
    char option;

    do
    {
        displayMenu();
        printf("Choose an option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            displayItems();
            addItemToCart();
            break;

        case '2':
            showCurrentTotal();
            break;

        case '3':
            if (confirmAction("checkout"))
            {
                checkout();
                clearCart();
            }
            break;

        case '4':
            if (confirmAction("cancel the session"))
            {
                clearCart();
                printf("Session cancelled. Cart cleared.\n");
            }
            break;

        case 'q':
            if (confirmAction("quit"))
            {
                printf("Exiting the program.\n");
            }
            break;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

    } while (option != 'q' || !confirmAction("quit"));

    return 0;
}
