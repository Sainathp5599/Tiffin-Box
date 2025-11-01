#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include"tiffinbox.h"


int validateName(char *username)
{
    int i = 0;
    while (username[i] != '\0')
    {
        if ((username[i] >= 'A' && username[i] <= 'Z') ||
            (username[i] >= 'a' && username[i] <= 'z') ||
            username[i] == 32) // allow space
        {
            i++;
        }
        else
        {
            return 0; // Invalid character
        }
    }
    return 1; // Valid name
}

int validatePhoneNumber(char *phoneNumber)
{
    int a = strlen(phoneNumber);
    int i = 0;
    if (phoneNumber[0] == '0')
        return 0; // Cannot start with 0

    // Check all digits and length
    while (phoneNumber[i] != '\0')
    {
        if (a == 10 && (phoneNumber[i] >= '0' && phoneNumber[i] <= '9'))
            i++;
        else
            return 0; // Invalid phone
    }

    return 1; // Valid phone
}

int validateTime(char *time)
{
    //if(strlen(time) != 8) { printf("Invalid length!\n"); return 0; }

    if(time[0] == '0') {
        if(!(time[1] >= '1' && time[1] <= '9')) { printf("Invalid hour!\n"); return 0; }
    }
    else if(time[0] == '1') {
        if(!(time[1] >= '0' && time[1] <= '2')) { printf("Invalid hour!\n"); return 0; }
    }
    else { printf("Invalid hour!\n"); return 0; }

    if(time[2] != ':') { printf("Missing ':'\n"); return 0; }

    if(!(time[3] >= '0' && time[3] <= '5') || !(time[4] >= '0' && time[4] <= '9')) { 
        printf("Invalid minutes!\n"); return 0; 
    }

    if(time[5] != ' ') { printf("Missing space before AM/PM\n"); return 0; }

    if(time[6] != 'A' && time[6] != 'P') { printf("AM/PM format error!\n"); return 0; }
    if(time[7] != 'M') { printf("AM/PM format error!\n"); return 0; }

    return 1; // valid
}
//-------------------------------------------------------------------------------------------
int flatNoValidate(char* flat)
{
    if (strlen(flat) == 0) {
        printf("Error: House/Flat number cannot be empty!\n");
        return 0;
    }

    int i = 0;
    int validCharFound = 0;  // to ensure at least one letter or digit

    while (flat[i] != '\0')
    {
        if ((flat[i] >= '0' && flat[i] <= '9') ||
            (flat[i] >= 'a' && flat[i] <= 'z') ||
            (flat[i] >= 'A' && flat[i] <= 'Z'))
        {
            validCharFound = 1;  // at least one alphanumeric
        }
        else if (flat[i] == ' ' || flat[i] == '/' || flat[i] == '-')
        {
            // allowed characters
        }
        else
        {
            printf("Error: Invalid character '%c' in House/Flat number! (Allowed: letters, digits, /, - , space)\n", flat[i]);
            return 0;
        }
        i++;
    }

    if (!validCharFound) {
        printf("Error: House/Flat number must contain at least one letter or digit!\n");
        return 0;
    }

    return 1; // valid
}

//----------------------------------------------------------------------------------------
int validateStreet(char *street) {
    if (strlen(street) == 0) {
        printf("Error: Street/Road cannot be empty!\n");
        return 0;
    }

    int i = 0;
    int hasAlpha = 0; // ensure at least one alphabet

    while (street[i] != '\0') {
        char ch = street[i];

        if (isalpha(ch)) {
            hasAlpha = 1; // contains alphabet
        }
        else if (isdigit(ch) || ch == ' ' || ch == '-' || ch == '.') {
            // allowed characters
        }
        else {
            printf("Error: Invalid character '%c' in Street/Road! (Allowed: letters, digits, space, -, .)\n", ch);
            return 0;
        }
        i++;
    }

    if (!hasAlpha) {
        printf("Error: Street/Road must contain at least one letter!\n");
        return 0;
    }

    return 1; // valid
}
//------------------------------------------------------------------------------------------

int validateCity(char *city) {
    if (strlen(city) == 0) {
        printf("Error: City cannot be empty!\n");
        return 0;
    }

    int i = 0;
    int hasAlpha = 0; // to ensure at least one alphabet

    while (city[i] != '\0') {
        char ch = city[i];

        if (isalpha(ch)) {
            hasAlpha = 1;
        }
        else if (ch == ' ') {
            // allowed
        }
        else {
            printf("Error: Invalid character '%c' in City! Only letters and spaces allowed.\n", ch);
            return 0;
        }
        i++;
    }

    if (!hasAlpha) {
        printf("Error: City must contain at least one letter!\n");
        return 0;
    }

    return 1; // valid
}
//------------------------------------------------------------------------------------

int validatePincode(char *pincode) {
    if (strlen(pincode) != 6) {
        printf("Error: Pincode must be exactly 6 digits!\n");
        return 0;
    }

    for (int i = 0; i < 6; i++) {
        if (!isdigit(pincode[i])) {
            printf("Error: Invalid character '%c' in Pincode! Only digits are allowed.\n", pincode[i]);
            return 0;
        }
    }

    return 1; // valid
}

//--------------------------------------------------------------------------------------


