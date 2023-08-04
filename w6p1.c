
/*
***************************
                          Workshop - #6 (P1)
Full Name  :Ankita Chandel
Student ID#:161317219
Email      :achandel1@seneca.ca
Section    :ZDD
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
***************************
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_items 10

#include <stdio.h>

int main(void)
{
    double income_input;
    const double MIN_mon_income = 500.00;
    const double MAX_mon_income = 400000.00;
    int items;
    double cost[MAX_items];
    const double MIN_cost = 100.00;
    int priority[MAX_items];
    char finance[MAX_items];
    int i;
    double total = 0;

    printf("+--------------------------+\n");
    printf("+ Wish List Forecaster     |\n");
    printf("+--------------------------+\n\n");
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income_input);

        if (income_input < MIN_mon_income)
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        if (income_input > MAX_mon_income)
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");

    } while (income_input < MIN_mon_income || income_input > MAX_mon_income);

    //wish list items forcast

    do {

        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &items);

        if (items <= 0 || items > MAX_items)
            printf("ERROR: List is restricted to between 1 and 10 items.\n");




    } while ((items <= 0 || items > MAX_items));
    // item details

    for (i = 0; i < items; i++) {

        printf("\nItem-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < MIN_cost)

                printf("      ERROR: Cost must be at least $100.00\n");
        } while (cost[i] < MIN_cost);

        // priority

        do {
            printf("   How important is it to you ? [1 = must have, 2 = important, 3 = want] : ");
            scanf("%d", &priority[i]);

            if (priority[i] <= 0 || priority[i] > 3)
                printf("      ERROR: Value must be between 1 and 3\n");

        } while (priority[i] <= 0 || priority[i] > 3);

        //finance

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);
            if (finance[i] != 'y' && finance[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (finance[i] != 'y' && finance[i] != 'n');
    }




    printf("\nItem Priority Financed Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < items; i++) {
        printf("  %d      %d        %c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
        total += cost[i];
    }
    // total calculation


    printf("---- -------- -------- -----------\n");
    printf("                       $%11.2lf\n\n", total);
    printf("Best of luck in all your future endeavours!\n");


    return 0;
}
