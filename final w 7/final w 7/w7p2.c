/*
***************************
Workshop - #7 (P1)
Full Name : Ankita Chandel
Student ID# : 161317219
Email : achandel1@myseneca.ca
Section : ZDD
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* **************************
*/

#define _CRT_SECURE_NO_WARNINGS

#define Max_length 70
#define Min_length 10
#define Max_moves 26
#define Min_moves 3
#define constant_var 0

#include <stdio.h>

// declaring structure 1 for player info

struct PlayerInfo
{
    char character_symbol;
    int number_of_lives;
    int Treasure;
    int Player_History[Max_length];
};

// declaring structure 2 for game info

struct GameInfo
{
    int path_length;
    int number_of_moves;
    int Bomb_location[Max_length];
    int Treasure_location[Max_length];
};



int main(void)
{

    int moves[20], next_move;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");


    struct PlayerInfo player;
    // created two variables for taking the input values
    scanf("%c", &player.character_symbol); // the value of character will store in this variable and eventually its data will be recoreded the playerInfo structure

    // Loop for no. of lives

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.number_of_lives);
        if ((player.number_of_lives > 10) || (player.number_of_lives < 1))
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while ((player.number_of_lives > 10) || (player.number_of_lives < 1));

    // loop end after that print the default statement

    printf("Player configuration set-up is complete\n");

    // Game confriguation starts
    printf("\nGAME Configuration\n");
    printf("------------------\n");

    // structure 2
    struct GameInfo game;

    //path_length

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.path_length);
        if ((game.path_length > Max_length) || (game.path_length < Min_length) || (game.path_length % 5 != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((game.path_length > Max_length) || (game.path_length < Min_length) || (game.path_length % 5 != 0));

    //number_of_moves

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.number_of_moves);
        if ((game.number_of_moves < player.number_of_lives || game.number_of_moves > game.path_length * 0.75))
        {
            printf("    Value must be between 3 and %d\n", (int)(game.path_length * 0.75));
        }
    } while ((game.number_of_moves < player.number_of_lives || game.number_of_moves > game.path_length * 0.75));

    // Bomb placement

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n"
        "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    int i, j;
    for ( i = 0; i < game.path_length / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);

        //Loop 2

        for ( j = 0; j < 5; j++)
        {
            scanf("%d", &game.Bomb_location[5 * i + j]);
        }
    }
    printf("BOMB placement set\n");

    // Treasure Placement

    printf("\nTREASURE Placement\n------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

    for ( i = 0; i < game.path_length / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);

        //Loop 2

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.Treasure_location[5 * i + j]);
        }
    }

    // ending of part 1

    printf("TREASURE placement set\n");
    printf("\nGAME configuration set-up is complete...\n");
    printf("\n------------------------------------\n"
        "TREASURE HUNT Configuration Settings\n"
        "------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.character_symbol);
    printf("   Lives      : %d\n", player.number_of_lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.path_length);
    printf("   Bombs      : ");
    for (i = 0; i < game.path_length; i++)
    {
        printf("%d", game.Bomb_location[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for ( i = 0; i < game.path_length; i++)
    {
        printf("%d", game.Treasure_location[i]);
    }
    printf("\n\n====================================\n"
        "~ Get ready to play TREASURE HUNT! ~\n"
        "====================================\n");

    // part 2 printing the initialized details

    for ( i = 0; i < game.path_length; i++)
    {
        printf(" ");
    }
    printf("\n");
    for ( i = 0; i < game.path_length; i++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 1; i <= game.path_length; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", i / 10);
        }
        else
        {
            printf("|");
        }
    }
    printf("\n");
    for (i = 1; i <= game.path_length; i++)
    {
        printf("%d", i % 10);
    }
    player.Treasure = 0;
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: % 2d | Treasures : % 2d | Moves Remaining : % 2d\n", player.number_of_lives, player.Treasure, game.number_of_moves);
    printf("+---------------------------------------------------+\n");

    // initializing done

    do
    {
        printf("\nNext Move [1-20]: ");
        scanf("%d", &next_move);
        if ((next_move < 0) || (next_move > game.number_of_moves))
        {
            printf("   \nOut of Range!!!");
        }
    } while ((next_move < 0) || (next_move > game.number_of_moves));

    for (i = 0; i < game.path_length; i++)
    {
        moves[i] == next_move;
    }

    if ((game.Bomb_location[next_move - 1] == 0) && game.Treasure_location[next_move - 1] == 0)
    {
        printf("\n===============> [.] ...Nothing found here... [.]\n");
        for (int i = 0; i < game.path_length; i++)
        {
            if (moves[i] == next_move)
                printf("%c", player.character_symbol);
            else
                printf(" ");
        }
        printf("\n");
        for ( i = 0; i < game.path_length; i++)
        {
            printf("-");
        }
        printf("\n");
        for ( i = 1; i <= game.path_length; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

    }
    return 0;
}

