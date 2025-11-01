#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tiffinbox.h"

void distributer(Tiffin *box)
{
    char pass[20];
    char id[20];

    printf("\nEnter ID: ");
    scanf("%s", id);

    printf("Enter Password: ");
    scanf("%s", pass);

    if (distributerLogin(pass, id))
    {
        printf("\n✅ Login successful!\n");

        distributermenu(box);
    }
}

int distributerLogin(char *pass, char *userid)
{
    // Hardcoded credentials
    if (strcmp(pass, "Sai@123") == 0 && strcmp(userid, "Sai5599") == 0)
    {
        return 1; // login successful
    }
    else
    {
        printf("\n❌ Incorrect ID or Password. Please try again.\n");

        return 0; // login failed
    }
}

//-----------------------------------------------------------------------------------------

void distributermenu(Tiffin *box)
{
    int dChoice;
    do
    {
        printf("\n====== ADMIN MENU =======\n");
        printf("-> 1. View All Orders\n");
        printf("-> 2. View Pending Orders\n");
        printf("-> 3. Update Order Status\n");
        printf("-> 4. Log Out\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &dChoice);
        getchar(); // clear newline

        switch (dChoice)
        {
        case 1:
            viewOrders(box); // show all orders
            break;

        case 2:
            viewPendingOrders(box); // show only pending
            break;

        case 3:
            updateOrderStatus(box); // mark order as delivered
            break;

        case 4:
            printf("Logging out...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (dChoice != 4);
}

//----------------------------------------------------------------------------------------

void viewPendingOrders(Tiffin *box)
{
    int found = 0;

    for (int i = 0; i < box->detailCount; i++)
    {
        if (box->contacts[i].status == 1) // Pending
        {
            found = 1;
            printf("----------------------------------------------------------\n");
            printf("\nName          : %s\n", box->contacts[i].name);
            printf("Phone Number  : %s\n", box->contacts[i].phone);
            printf("Delivery Time : %s\n", box->contacts[i].time);
            printf("Address       : %s, %s, %s - %s\n",
                   box->contacts[i].house,
                   box->contacts[i].street,
                   box->contacts[i].city,
                   box->contacts[i].pincode);
            printf("Status        : Pending\n");
            printf("----------------------------------------------------------\n");
        }
    }

    if (!found)
        printf("\n❌  You have no pending orders.\n");
}

//----------------------------------------------------------------------------------------------

void viewOrders(Tiffin *box)
{
    int found = 0;

    if (box->detailCount == 0)
    {
        printf("\nNo orders found!\n");
        return;
    }

    for (int i = 0; i < box->detailCount; i++)
    {
        if (box->contacts[i].status == 0)
            continue; // skip if no order

        found = 1;
        printf("----------------------------------------------------------\n");
        printf("Order #%d\n", i + 1);
        printf("Name       : %s\n", box->contacts[i].name);
        printf("Phone      : %s\n", box->contacts[i].phone);
        printf("Address    : %s, %s, %s - %s\n",
               box->contacts[i].house,
               box->contacts[i].street,
               box->contacts[i].city,
               box->contacts[i].pincode);
        printf("Delivery   : %s\n", box->contacts[i].time);

        printf("Items      : ");
        int firstItem = 1;
        if (box->contacts[i].qtyChapati > 0)
        {
            printf("Chapati x%d", box->contacts[i].qtyChapati);
            firstItem = 0;
        }
        if (box->contacts[i].qtySabji > 0)
        {
            if (!firstItem)
                printf(", ");
            printf("Sabji x%d", box->contacts[i].qtySabji);
            firstItem = 0;
        }
        if (box->contacts[i].qtyRice > 0)
        {
            if (!firstItem)
                printf(", ");
            printf("Rice x%d", box->contacts[i].qtyRice);
            firstItem = 0;
        }
        if (box->contacts[i].qtyDal > 0)
        {
            if (!firstItem)
                printf(", ");
            printf("Dal x%d", box->contacts[i].qtyDal);
            firstItem = 0;
        }
        if (box->contacts[i].qtySweet > 0)
        {
            if (!firstItem)
                printf(", ");
            printf("Sweet x%d", box->contacts[i].qtySweet);
        }
        printf("\n");

        printf("Status     : %s\n",
               box->contacts[i].status == 1 ? "Pending" : box->contacts[i].status == 2 ? "Delivered"
                                                                                       : "No Order");
        printf("----------------------------------------------------------\n");
    }

    if (!found)
        printf("\nNo active orders found!\n");
}

//-----------------------------------------------------------------------------------

void updateOrderStatus(Tiffin *box)
{
    if (box->detailCount == 0)
    {
        printf("\nNo orders available to update.\n");
        return;
    }

    int orderNo;
    viewOrders(box); // Show all orders first

    printf("\nEnter the Order Number to update: ");
    scanf("%d", &orderNo);

    if (orderNo < 1 || orderNo > box->detailCount)
    {
        printf("❌ Invalid Order Number!\n");
        return;
    }

    int index = orderNo - 1; // Convert to array index
    printf("Current Status: %s\n",
           (box->contacts[index].status == 1) ? "Pending" : (box->contacts[index].status == 2) ? "Delivered"
                                                                                               : "No Order");

    printf("Enter new status (1 = Pending, 2 = Delivered): ");
    int newStatus;
    scanf("%d", &newStatus);

    if (newStatus != 1 && newStatus != 2)
    {
        printf("❌ Invalid status value!\n");
        return;
    }

    box->contacts[index].status = newStatus;
    printf("\n✅ Order #%d status updated successfully!\n", orderNo);
}
