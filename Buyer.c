#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tiffinbox.h"

void Buyer(Tiffin *box, int i)
{
    int bChoice;
    do
    {
        if (box->contacts[i].status == 0 || box->contacts[i].status == 2)
        {
            printf("\n====== BUYER MENU ======\n");
            printf("-> 1. Show Today's Menu\n");
            printf("-> 2. Add Order\n");
            printf("-> 3. View Order\n");
            printf("-> 4. Log Out\n");
            printf("=========================\n");
            printf("Select an option: ");
            scanf("%d", &bChoice);
            getchar(); // clear newline

            switch (bChoice)
            {
            case 1:
            {
                printf("\n===================================================\n");
                printf("                   🍛 TODAY'S MENU                   \n");
                printf("===================================================\n");
                printf("| %-12s | %-25s | %-6s|\n", "Item", "Description", "Price");
                printf("---------------------------------------------------\n");
                printf("| %-12s | %-25s | ₹%-5d|\n", "Chapati", "2 pcs", 10);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Sabji", "Paneer Butter Masala", 40);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Rice", "Jeera Rice", 25);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Dal", "Dal Tadka", 20);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Sweet", "Gulab Jamun", 15);
                printf("===================================================\n");
            }
            break;
            case 2:
                addOrder(box, i); // place an order
                showBill(box, i);
                break;
            case 3:
                viewBuyerOrder(box, i); // see their orders
                break;
            case 4:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice!\n");
            }
        }
        else
        {
            printf("\n====== BUYER MENU ======\n");
            printf("-> 1. Show Today's Menu\n");
            printf("-> 2. Cancel Order\n");
            printf("-> 3. View Order\n");
            printf("-> 4. Log Out\n");
            printf("=========================\n");
            printf("Select an option: ");
            scanf("%d", &bChoice);
            getchar(); // clear newline

            switch (bChoice)
            {
            case 1:
                printf("\n===================================================\n");
                printf("                   🍛 TODAY'S MENU                   \n");
                printf("===================================================\n");
                printf("| %-12s | %-25s | %-6s|\n", "Item", "Description", "Price");
                printf("---------------------------------------------------\n");
                printf("| %-12s | %-25s | ₹%-5d|\n", "Chapati", "2 pcs", 10);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Sabji", "Paneer Butter Masala", 40);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Rice", "Jeera Rice", 25);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Dal", "Dal Tadka", 20);
                printf("| %-12s | %-25s | ₹%-5d|\n", "Sweet", "Gulab Jamun", 15);
                printf("===================================================\n");
                // display available items
                break;
            case 2:
                cancelOrder(box, i); // ✅ correct function for cancel
                break;
            case 3:
                viewBuyerOrder(box, i); // see their orders
                break;
            case 4:
                printf("\n🔒 Logging out...\n");
                break;
            default:
                printf("Invalid choice!\n");
            }
        }
    } while (bChoice != 4);
}
//----------------------------------------------------------------------------

void viewBuyerOrder(Tiffin *box, int index)
{
    if (box->contacts[index].status == 0)
    {
        printf("\nℹ️  You have not placed any order yet.\n");
        return;
    }

    printf("\n=============================================\n");
    printf("           🥗 BUYER ORDER DETAILS 🥗          \n");
    printf("=============================================\n");

    printf("👤 Name          : %s\n", box->contacts[index].name);
    printf("📞 Phone Number  : %s\n", box->contacts[index].phone);
    printf("🏠 Address       : %s, %s, %s - %s\n",
           box->contacts[index].house,
           box->contacts[index].street,
           box->contacts[index].city,
           box->contacts[index].pincode);
    printf("⏰ Delivery Time : %s\n", box->contacts[index].time);
    printf("📦 Status        : %s\n",
           (box->contacts[index].status == 1)   ? "Pending"
           : (box->contacts[index].status == 2) ? "Delivered"
                                                : "No Order");

    printf("---------------------------------------------\n");
    printf("%-12s %-8s %-10s\n", "Item", "Qty", "Unit Price");
    printf("---------------------------------------------\n");

    int priceChapati = 5;
    int priceSabji = 40;
    int priceRice = 50;
    int priceDal = 40;
    int priceSweet = 20;

    if (box->contacts[index].qtyChapati > 0)
        printf("%-12s %-8d ₹%-10d\n", "Chapati", box->contacts[index].qtyChapati, priceChapati);
    if (box->contacts[index].qtySabji > 0)
        printf("%-12s %-8d ₹%-10d\n", "Sabji", box->contacts[index].qtySabji, priceSabji);
    if (box->contacts[index].qtyRice > 0)
        printf("%-12s %-8d ₹%-10d\n", "Rice", box->contacts[index].qtyRice, priceRice);
    if (box->contacts[index].qtyDal > 0)
        printf("%-12s %-8d ₹%-10d\n", "Dal", box->contacts[index].qtyDal, priceDal);
    if (box->contacts[index].qtySweet > 0)
        printf("%-12s %-8d ₹%-10d\n", "Sweet", box->contacts[index].qtySweet, priceSweet);

    int total = (box->contacts[index].qtyChapati * priceChapati) +
                (box->contacts[index].qtySabji * priceSabji) +
                (box->contacts[index].qtyRice * priceRice) +
                (box->contacts[index].qtyDal * priceDal) +
                (box->contacts[index].qtySweet * priceSweet);

    printf("---------------------------------------------\n");
    printf("%-21s ₹%-10d\n", "Total Amount:", total);
    printf("=============================================\n");
    printf("   Thank you for ordering with TiffinBox! 🙏\n");
    printf("=============================================\n");
}

//-------------------------------------------------------------------------------------

void showBill(Tiffin *box, int index)
{
    int priceChapati = 5;
    int priceSabji = 40;
    int priceRice = 50;
    int priceDal = 40;
    int priceSweet = 20;

    int total = box->contacts[index].qtyChapati * priceChapati +
                box->contacts[index].qtySabji * priceSabji +
                box->contacts[index].qtyRice * priceRice +
                box->contacts[index].qtyDal * priceDal +
                box->contacts[index].qtySweet * priceSweet;

    printf("\n=====================================\n");
    printf("           🍱 TIFFIN BILL 🍱          \n");
    printf("=====================================\n");
    printf("Customer Name : %s\n", box->contacts[index].name);
    printf("-------------------------------------\n");
    printf("%-12s %-8s %-10s\n", "Item", "Qty", "Price");
    printf("-------------------------------------\n");

    if (box->contacts[index].qtyChapati > 0)
        printf("%-12s %-8d ₹%-10d\n", "Chapati", box->contacts[index].qtyChapati, box->contacts[index].qtyChapati * priceChapati);
    if (box->contacts[index].qtySabji > 0)
        printf("%-12s %-8d ₹%-10d\n", "Sabji", box->contacts[index].qtySabji, box->contacts[index].qtySabji * priceSabji);
    if (box->contacts[index].qtyRice > 0)
        printf("%-12s %-8d ₹%-10d\n", "Rice", box->contacts[index].qtyRice, box->contacts[index].qtyRice * priceRice);
    if (box->contacts[index].qtyDal > 0)
        printf("%-12s %-8d ₹%-10d\n", "Dal", box->contacts[index].qtyDal, box->contacts[index].qtyDal * priceDal);
    if (box->contacts[index].qtySweet > 0)
        printf("%-12s %-8d ₹%-10d\n", "Sweet", box->contacts[index].qtySweet, box->contacts[index].qtySweet * priceSweet);

    printf("-------------------------------------\n");
    printf("%-21s ₹%-10d\n", "Total Amount:", total);
    printf("=====================================\n");
    printf("     Thank you for your order! 🙏  \n");
    printf("=====================================\n");
}

//----------------------------------------------------------------------------------------------
int buyerLogin(Tiffin *box)
{
    char username[50], password[20];
    printf("\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < box->detailCount; i++)
    {
        if (strcmp(username, box->contacts[i].userName) == 0 &&
            strcmp(password, box->contacts[i].password) == 0)
        {
            printf("\n\033[1;32m✅ Login Successful!\033[0m\n");

            return i; // return index of logged-in buyer
        }
    }

    printf("Invalid username or password.\n");
    return -1;
}

void registration(Tiffin *box)
{
    char username[50];
    char password[20];

    printf("\n");

    while (1)
    {
        printf("Enter User Name: ");
        scanf(" %49[^\n]", username); // limit input to 49 chars

        // Check if username already exists
        int exists = 0;
        for (int i = 0; i < box->detailCount; i++)
        {
            if (strcmp(username, box->contacts[i].userName) == 0)
            {
                exists = 1;
                break;
            }
        }

        if (exists)
        {
            printf("⚠️  Username already exists. Try another one\n\n");
        }
        else
        {
            break; // username is unique
        }
    }

    printf("Enter Password: ");
    scanf(" %19[^\n]", password); // limit input to 19 chars

    // Save to contacts with strncpy
    strncpy(box->contacts[box->detailCount].userName, username, sizeof(box->contacts[box->detailCount].userName) - 1);
    box->contacts[box->detailCount].userName[sizeof(box->contacts[box->detailCount].userName) - 1] = '\0';

    strncpy(box->contacts[box->detailCount].password, password, sizeof(box->contacts[box->detailCount].password) - 1);
    box->contacts[box->detailCount].password[sizeof(box->contacts[box->detailCount].password) - 1] = '\0';

    box->detailCount++;

    printf("Registration successful!✅\n");
    saveData(box);
}

//--------------------------------------------------------------------------------------

void addOrder(Tiffin *box, int index)
{
    char temp[50];

    printf("\n====================================\n");
    printf("         PLACE YOUR ORDER           \n");
    printf("====================================\n");

    // ---------------- NAME ----------------
    do
    {
        printf("Enter Your Name: ");
        scanf(" %49[^\n]", temp);
        if (validateName(temp))
        {
            strncpy(box->contacts[index].name, temp, sizeof(box->contacts[index].name) - 1);
            box->contacts[index].name[sizeof(box->contacts[index].name) - 1] = '\0';
            break;
        }
        else
        {
            printf("❌ Invalid Name. Try again.\n");
        }
    } while (1);

    // ---------------- PHONE ----------------
    do
    {
        printf("Enter Your Phone Number: ");
        scanf(" %19[^\n]", temp); // max 19 chars
        if (validatePhoneNumber(temp))
        {
            strncpy(box->contacts[index].phone, temp, sizeof(box->contacts[index].phone) - 1);
            box->contacts[index].phone[sizeof(box->contacts[index].phone) - 1] = '\0';
            break;
        }
        else
        {
            printf("❌ Invalid Phone Number. Try again.\n");
        }
    } while (1);

    // ---------------- HOUSE / FLAT ----------------
    do
    {
        printf("Enter House/Flat No: ");
        scanf(" %49[^\n]", temp);
        if (flatNoValidate(temp))
        {
            strncpy(box->contacts[index].house, temp, sizeof(box->contacts[index].house) - 1);
            box->contacts[index].house[sizeof(box->contacts[index].house) - 1] = '\0';
            break;
        }
        else
        {
            printf("❌ Invalid House/Flat No. Try again.\n");
        }
    } while (1);

    // ---------------- STREET ----------------
    do
    {
        printf("Enter Street/Road: ");
        scanf(" %49[^\n]", temp);
        if (validateStreet(temp))
        {
            strncpy(box->contacts[index].street, temp, sizeof(box->contacts[index].street) - 1);
            box->contacts[index].street[sizeof(box->contacts[index].street) - 1] = '\0';
            break;
        }
        else
        {
            printf("❌ Invalid Street/Road. Try again.\n");
        }
    } while (1);

    // ---------------- CITY ----------------
    do
    {
        printf("Enter City: ");
        scanf(" %29[^\n]", temp); // city buffer max 30
        if (validateCity(temp))
        {
            strncpy(box->contacts[index].city, temp, sizeof(box->contacts[index].city) - 1);
            box->contacts[index].city[sizeof(box->contacts[index].city) - 1] = '\0';
            break;
        }
        else
        {
            printf("❌ Invalid City. Try again.\n");
        }
    } while (1);

    // ---------------- PINCODE ----------------
    do
    {
        printf("Enter Pincode: ");
        scanf(" %9[^\n]", temp); // pincode max 10 chars
        if (validatePincode(temp))
        {
            strncpy(box->contacts[index].pincode, temp, sizeof(box->contacts[index].pincode) - 1);
            box->contacts[index].pincode[sizeof(box->contacts[index].pincode) - 1] = '\0';
            break;
        }
        else
        {
            printf("❌ Invalid Pincode. Try again.\n");
        }
    } while (1);

    // ---------------- DELIVERY TIME ----------------
    do
    {
        printf("Enter Delivery Time (HH:MM AM/PM): ");
        scanf(" %9[^\n]", temp); // max 10 chars
        if (validateTime(temp))
        {
            strncpy(box->contacts[index].time, temp, sizeof(box->contacts[index].time) - 1);
            box->contacts[index].time[sizeof(box->contacts[index].time) - 1] = '\0';
            break;
        }
        else
        {
            printf("❌ Invalid Time Format. Try again.\n");
        }
    } while (1);

    // ---------------- QUANTITIES ----------------
    printf("Enter quantity of Chapati: ");
    scanf("%d", &box->contacts[index].qtyChapati);

    printf("Enter quantity of Sabji: ");
    scanf("%d", &box->contacts[index].qtySabji);

    printf("Enter quantity of Rice: ");
    scanf("%d", &box->contacts[index].qtyRice);

    printf("Enter quantity of Dal: ");
    scanf("%d", &box->contacts[index].qtyDal);

    printf("Enter quantity of Sweet: ");
    scanf("%d", &box->contacts[index].qtySweet);

    box->contacts[index].status = 1; // pending
    saveData(box);
    printf("\n✅ Order placed successfully!\n");
}

//-------------------------------------------------------------------------------------

void cancelOrder(Tiffin *box, int index)
{
    if (box->contacts[index].status == 0)
    {
        printf("\n❌ No active order found to cancel.\n");
        return;
    }

    printf("\n⚠️ Are you sure you want to cancel your order? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        // Reset order details
        box->contacts[index].qtyChapati = 0;
        box->contacts[index].qtySabji = 0;
        box->contacts[index].qtyRice = 0;
        box->contacts[index].qtyDal = 0;
        box->contacts[index].qtySweet = 0;

        box->contacts[index].status = 0; // back to no order
        printf("\n✅ Your order has been cancelled successfully!\n");
        saveData(box);
    }
    else
    {
        printf("\nℹ️ Order cancellation aborted.\n");
    }
}
