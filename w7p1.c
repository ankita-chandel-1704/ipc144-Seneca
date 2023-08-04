/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  :Ankita Chandel
Student ID#:161317219
Email      :achandel1@myseneca.ca
Section    :ZDD
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#define maximum_path_length 35

#include <stdio.h>
int no_of_lives;

struct Playerinfo {

    
    char player;
    int no_of_lives;
    int treasure_counter;
    int position_history[maximum_path_length];
};
struct Gameinfo {

    int max_no_of_moves;
    int path_length;
    int bombs[maximum_path_length];
    int treasures[maximum_path_length];
};

int main(void)
{
    struct Playerinfo type1;

    struct Gameinfo type2;
    
    int i, j;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\nPLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &type1.player);

    do {

        printf("Set the number of lives: ");
        scanf("%d", &type1.no_of_lives);
        if (type1.no_of_lives < 1 || type1.no_of_lives > 10) {
            printf("     Must be between 1 and 10!\n");
        }
        else {
            printf("Player configuration set-up is complete\n");
        }

    } while (type1.no_of_lives < 1 || type1.no_of_lives > 10);

    printf("\nGAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &type2.path_length);
        if (type2.path_length % 5 == 0 && (type2.path_length >= 10 && type2.path_length <= 70)) {
        }
        else{
            printf("     Must be a multiple of 5 and between 10-70!!!\n");

        }
    } while (type2.path_length % 5 != 0 || type2.path_length < 10 || type2.path_length > 70);
    
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &type2.max_no_of_moves);
        if (type2.max_no_of_moves >= type1.no_of_lives && type2.max_no_of_moves <= 0.75 * type2.path_length) {

        }
        else {
            printf("    Value must be between 3 and 26\n");
        }


    } while (type2.max_no_of_moves < type1.no_of_lives || type2.max_no_of_moves > 0.75 * type2.path_length);

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    for ( i = 0; i < type2.path_length / 5; i++) {
        printf("   Positions [%2d-%2d]: ",(i*5)+1,(i*5)+5);
        for ( j = 0; j < 5; j++) {
            scanf("%d", &type2.bombs[(i * 5)+j]);

        }
    }
    printf("BOMB placement set\n");
    printf("\nTREASURE Placement\n");
       
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
        for (i = 0; i < type2.path_length / 5; i++) {
            printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);
            for (j = 0; j < 5; j++) {
                scanf("%d", &type2.treasures[(i * 5) + j]);

            }
        }
        printf("TREASURE placement set");
        printf("\n\nGAME configuration set-up is complete...\n\n");
        printf("------------------------------------\n");
        printf("TREASURE HUNT Configuration Settings\n");
        printf("------------------------------------\n");
        printf("Player:\n");
        printf("   Symbol     : %c\n", type1.player);
        printf("   Lives      : %d\n", type1.no_of_lives);
        printf("   Treasure   : [ready for gameplay]\n");
        printf("   History    : [ready for gameplay]\n");
        printf("\nGame:");
        printf("\n   Path Length: %d", type2.path_length);
        printf("\n   Bombs      : ");
        for (i = 0; i < type2.path_length; i++) 
        {
            printf("%d", type2.bombs[i]);
        }

        printf("\n   Treasure   : ");
        for (i = 0; i < type2.path_length; i++)
        {
            printf("%d", type2.treasures[i]);
        }

        printf("\n\n====================================\n");
        printf("~ Get ready to play TREASURE HUNT! ~\n");
        printf("====================================\n");
    return 0;
    
}
