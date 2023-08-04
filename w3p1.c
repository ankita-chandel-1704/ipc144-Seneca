/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int product1_Id = 111;
    const int product2_Id = 222;
    const int product3_Id = 111;

    const double price1 = 111.4900;
    const double price2 = 222.9900;
    const double price3 = 334.4900;

    const char taxp1 = 'Y';
    const char taxp2 = 'N';
    const char taxp3 = 'N';



    printf("Product Information\n");
    printf("===================\n");

    printf("Product-1 (ID:%d)\n", product1_Id);
    printf("  Taxed: %c\n", taxp1);
    printf("  Price: $%.4lf\n\n", price1);
    printf("Product-2 (ID:%d)\n", product2_Id);
    printf("  Taxed: %c\n", taxp2);
    printf("  Price: $%.4lf\n\n", price2);
    printf("Product-3 (ID:%d)\n", product3_Id);
    printf("  Taxed: %c\n", taxp3);
    printf("  Price: $%.4lf\n\n", price3);


    const double average_price = 222.9900;
    printf("The average of all prices is: $%.4lf\n\n", average_price);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");

    int ans;

    if (taxp1 == 'Y');
    ans = 1;

    printf("1. Is product 1 taxable? -> %d\n\n", ans);

    if (taxp2 && taxp3 == 'N');
    ans = 1;
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", ans);
    if (price3 < testValue);
    ans = 0;


    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, ans);
    if (price3 > price2 && price1);
    ans = 1;
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", ans);

    if (price1 >= price3 - price2);
    ans = 0;
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", ans, price3 - price2);

    if (price2 >= average_price);
    ans = 1;
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", ans);


    printf("7. Based on product ID, product 1 is unique -> %d\n\n", product1_Id == (product2_Id && product3_Id));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", product2_Id != product1_Id && product2_Id != product3_Id);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", product3_Id == (product2_Id && product1_Id));




    return 0;
}