/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name : Ankita Chandel
Student ID#: 161317219
Email : achandel1@myseneca.ca
Section : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "core.h"
//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
int inputInt()
{
    int user = -1;
    char last = '\0';
    int skip = 1;
    do
    {
        scanf("%d%c", &user, &last);
        if (last != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else
        {
            skip = 0;
        }
    } while (skip);
    return user;
}
int inputIntPositive()
{
    int user = -1;
    do
    {
        user = inputInt();
    } while (user < 0 && printf("ERROR! Value must be > 0: "));
    return user;
}
int inputIntRange(int minimum, int maximum)
{
    int user = minimum - 1;
    do
    {
        user = inputInt();
    } while ((user < minimum || user > maximum) && printf("ERROR! Value must be between %d and %d inclusive: ", minimum, maximum));
    return user;
}

char inputCharOption(const char* string)
{
    char userChar;
    int skip = 1;
    do
    {
        userChar = getchar();
        if (strchr(string, userChar) != NULL)
        {
            return userChar;
            skip = 0;
        }
        else
        {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
    } while (skip);
    return 0;
}
//Function 5
void inputCString(char* char_String, int min, int max)
{
    char max_input[100] = { '\0' };
    int flag_1 = 0;
    int i = 0;
    int j = 0;
    do
    {
        scanf("%99[^\n]%*c", max_input);
        for (i = 1; max_input[i]; i++)
            ;
        if (min == max)
        {
            if (i == min)
            {
                for (j = 0; max_input[j]; char_String[j] = max_input[j], j++);
                char_String[j] = '\0';
                flag_1 = 1;
            }
        }
        else
        {
            if (i >= min && i <= max)
            {
                for (j = 0; max_input[j]; char_String[j] = max_input[j], j++);
                char_String[j] = '\0';
                flag_1 = 1;
            }
        }
        if (!flag_1)
        {
            if (min == max)
            {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else if (min == 0 || i > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
    } while (!flag_1);
}
void displayFormattedPhone(const char* char_String)
{
    int flag_2 = 1;
    int k = 0;
    if (char_String != NULL)
    {
        for (k = 0; char_String[k] && flag_2; k++)
        {
            if (char_String[k] < 48 || char_String[k] > 57)
            {
                flag_2 = 0;
            }
        }
    }
    if (flag_2 && k == 10)
    {
        printf("(");
        for (k = 0; k < 3; k++)
            printf("%c", char_String[k]);
        printf(")");
        for (k = 3; k < 6; k++)
            printf("%c", char_String[k]);
        printf("-");
        for (k = 6; k < 10; k++)
            printf("%c", char_String[k]);
    }
    else
    {
        printf("(___)___-____");
    }
}
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////