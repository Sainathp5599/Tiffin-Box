#ifndef TIFFIN_H
#define TIFFIN_H

#define MAX_CONTACTS 100

typedef struct
{
    char userName[20];
    char password[20];
    char name[50];
    char phone[20];
    char address[100];
    char time[10];
    char house[50];
    char street[50];
    char city[30];
    char pincode[10];
    int status;

    int qtyChapati;
    int qtySabji;
    int qtyRice;
    int qtyDal;
    int qtySweet;
} Details;

typedef struct
{
    int detailCount;
    Details contacts[100];
} Tiffin;

void addOrder(Tiffin *box, int index);
void viewOrders(Tiffin *box);

int validateName(char *username);
int validatePhoneNumber(char *phoneNumber);
int validateTime(char *time);
int flatNoValidate(char *flat);
int validateStreet(char *street);
int validateCity(char *city);
int validatePincode(char *pincode);
void registration(Tiffin *box);
int buyerLogin(Tiffin *box);
void Buyer(Tiffin *box, int i);
void viewBuyerOrder(Tiffin *box, int index);
void showBill(Tiffin *box, int index);
void distributer(Tiffin *box);
int distributerLogin(char *pass, char *userid);
void distributermenu(Tiffin *box);
void viewPendingOrders(Tiffin *box);
void updateOrderStatus(Tiffin *box);
void cancelOrder(Tiffin *box, int index);
void loadData(Tiffin *box);
void saveData(Tiffin *box);
void showTodaysMenu();
#endif