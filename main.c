#include <stdio.h>
#include "tiffinbox.h"

int main()
{
    Tiffin box;
    int choice;
    loadData(&box);

    do
    {
        printf("\n====== TIFFIN BOX ======\n");
        printf("-> 1. Buyer Registration\n");
        printf("-> 2. Buyer Login\n");
        printf("-> 3. Distributor Login\n");
        printf("-> 4. Exit\n");
        printf("=========================\n");
        printf("Select an option: ");

        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice)
        {
        case 1:
            registration(&box);
            break;

        case 2:
        {
            int i = buyerLogin(&box);
            if (i != -1)
                Buyer(&box, i);
            break;
        }

        case 3:
            distributer(&box);
            break;

        case 4:
            printf("Exiting...\n");
            saveData(&box);
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}