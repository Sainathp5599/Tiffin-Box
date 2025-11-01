#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"tiffinbox.h"

void loadData(Tiffin *box)
{
    FILE *fp = fopen("tiffinData.txt", "r");
    if (fp == NULL)
    {
        box->detailCount = 0;
        return;
    }

    fscanf(fp, "%d\n", &box->detailCount);

    for (int i = 0; i < box->detailCount; i++)
    {
        Details *c = &box->contacts[i];
        char line[512];

        if (fgets(line, sizeof(line), fp) == NULL)
            break;

        line[strcspn(line, "\n")] = 0; // remove newline

        char *token;

        // userName
        token = strtok(line, ",");
        strcpy(c->userName, token ? token : "");

        // password
        token = strtok(NULL, ",");
        strcpy(c->password, token ? token : "");

        // name
        token = strtok(NULL, ",");
        strcpy(c->name, token ? token : "");

        // phone
        token = strtok(NULL, ",");
        strcpy(c->phone, token ? token : "");

        // address (can be empty)
        token = strtok(NULL, ",");
        strcpy(c->address, token ? token : "");

        // time
        token = strtok(NULL, ",");
        strcpy(c->time, token ? token : "");

        // house
        token = strtok(NULL, ",");
        strcpy(c->house, token ? token : "");

        // street
        token = strtok(NULL, ",");
        strcpy(c->street, token ? token : "");

        // city
        token = strtok(NULL, ",");
        strcpy(c->city, token ? token : "");

        // pincode
        token = strtok(NULL, ",");
        strcpy(c->pincode, token ? token : "");

        // status
        token = strtok(NULL, ",");
        c->status = token ? atoi(token) : 0;

        // qtyChapati
        token = strtok(NULL, ",");
        c->qtyChapati = token ? atoi(token) : 0;

        // qtySabji
        token = strtok(NULL, ",");
        c->qtySabji = token ? atoi(token) : 0;

        // qtyRice
        token = strtok(NULL, ",");
        c->qtyRice = token ? atoi(token) : 0;

        // qtyDal
        token = strtok(NULL, ",");
        c->qtyDal = token ? atoi(token) : 0;

        // qtySweet
        token = strtok(NULL, ",");
        c->qtySweet = token ? atoi(token) : 0;
    }

    fclose(fp);
}
void saveData(Tiffin *box)
{
    FILE *fp = fopen("tiffinData.txt", "w");
    if (fp == NULL)
    {
        printf("Error saving data!\n");
        return;
    }

    // Write total number of contacts first
    fprintf(fp, "%d\n", box->detailCount);

    for (int i = 0; i < box->detailCount; i++)
    {
        Details c = box->contacts[i];
        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d\n",
                c.userName, c.password, c.name, c.phone, c.address, c.time,
                c.house, c.street, c.city, c.pincode,
                c.status, c.qtyChapati, c.qtySabji, c.qtyRice, c.qtyDal, c.qtySweet);
    }

    fclose(fp);
}

#include <stdio.h>

#include <stdio.h>

void showTodaysMenu()
{
    FILE *fp = fopen("menu.txt", "r");
    if (fp == NULL)
    {
        printf("Error: menu file not found!\n");
        return;
    }

    char line[100];
    char item[50], desc[50];
    int price;

    printf("\n==============================\n");
    printf("        🍛 TODAY'S MENU        \n");
    printf("==============================\n");

    while (fgets(line, sizeof(line), fp))
    {
        // Remove newline at end if present
        line[strcspn(line, "\n")] = 0;

        // Parse line like "Chapati=2 pcs=10"
        if (sscanf(line, "%49[^=]=%49[^=]=%d", item, desc, &price) == 3)
        {
            printf("%-15s : %-25s Price: ₹%d\n", item, desc, price);
        }
    }

    printf("==============================\n");

    fclose(fp);
}


