/*
***************************
Workshop - #7 (P1)
Full Name : Ankita Chandel
Student ID#  : 161317219
Email : achandel1@myseneca.ca
Section : ZDD
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* **************************
*/

#define _CRT_SECURE_NO_WARNINGS
#define Max_Lives 10
#define Min_Lives 1
#define Max_Length 70
#define Min_Length 10
#define Max_moves 26
#define Min_moves 3
#define constant 5
#define undiscovered '-'
#define bomb '!'
#define treasure '$'
#define hit_both '&'
#define hit_none '.'

#include <stdio.h>

struct PlayerInfo
{
    char character_symbol;
    int number_of_lives;
    int Treasure;
    int Player_History[Max_Length];
};
struct game
{
    int path_length;
    int number_of_moves;
    int Bomb_location[Max_Length];
    int Treasure_location[Max_Length];
};

int main(void)
{
    int counter1, counter2;
    int min = 3;
    int max = 26;
    int flag1 = 0;
    int flag2 = 0;
    int nextmove = 0;
    struct PlayerInfo player;
    struct game playergame;
    player.Treasure = 0;


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.character_symbol);
    while (flag1 == 0)
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.number_of_lives);
        if (player.number_of_lives<Min_Lives || player.number_of_lives>Max_Lives)
        {
            printf("     Must be between 1 and 10!\n");
        }
        if (player.number_of_lives >= Min_Lives && player.number_of_lives <= Max_Lives)
        {
            flag1 = 1;
        }
    }
    flag1 = 0;
    printf("Player configuration set-up is complete\n\n");
    for (counter1 = 0; counter1 < Max_Length; counter1++)
    {
        player.Player_History[counter1] = 0;
    }
    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &playergame.path_length);
        if (playergame.path_length < Min_Length || playergame.path_length>Max_Length || playergame.path_length % constant != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (playergame.path_length<Min_Length || playergame.path_length>Max_Length || playergame.path_length % constant != 0);
    max = (playergame.path_length * 0.75);
    flag1 = 0; while (flag1 == 0)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &playergame.number_of_moves); if (playergame.number_of_moves < min || playergame.number_of_moves > max)
        {
            printf("    Value must be between %d and %d\n", min, max);
        }
        if (playergame.number_of_moves >= min && playergame.number_of_moves <= max)
        {
            flag1 = 1;
        }
    }
    flag1 = 0;
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", playergame.path_length);
    for (counter1 = 0; counter1 < (playergame.path_length / constant); counter1++)
    {
        printf("   Positions [%2d-%2d]: ", constant * counter1 + 1, constant * counter1 + constant);
        for (counter2 = 0; counter2 < constant; counter2++)
        {
            scanf("%d", &playergame.Bomb_location[counter2 + constant * counter1]);
        }
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", playergame.path_length);
    for (counter1 = 0; counter1 < (playergame.path_length / constant); counter1++)
    {
        printf("   Positions [%2d-%2d]: ", constant * counter1 + 1, constant * counter1 + constant);
        for (counter2 = 0; counter2 < constant; counter2++)
        {
            scanf("%d", &playergame.Treasure_location[counter2 + constant * counter1]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.character_symbol);
    printf("   Lives      : %d\n", player.number_of_lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", playergame.path_length);
    printf("   Bombs      : ");
    for (counter1 = 0; counter1 < playergame.path_length; counter1++)
    {
        printf("%d", playergame.Bomb_location[counter1]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (counter1 = 0; counter1 < playergame.path_length; counter1++)
    {
        printf("%d", playergame.Treasure_location[counter1]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    flag1 = 0;
    flag2 = 0;
    do

    {
        if (flag2 == 0)
        {
            printf("\n  "); flag2 = 1;
        }
        else
        {
            printf("\n  ");
            for (counter1 = 0; counter1 < nextmove; counter1++)
            {
                if (player.Player_History[counter1] == 1 && counter1 == (nextmove - 1))
                {
                    printf("%c", player.character_symbol);
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n  ");
        }
        for (counter1 = 0; counter1 < playergame.path_length; counter1++)
        {
            if (player.Player_History[counter1] == 0)
            {
                printf("%c", undiscovered);
            }
            else if (playergame.Bomb_location[counter1] == 1 && playergame.Treasure_location[counter1] == 1)
            {
                printf("%c", hit_both);
            }
            else if (playergame.Bomb_location[counter1] == 1)
            {
                printf("%c", bomb);
            }
            else if (playergame.Treasure_location[counter1] == 1)
            {
                printf("%c", treasure);
            }
            else
            {
                printf("%c", hit_none);
            }
        }
        printf("\n  ");
        for (counter1 = 1; counter1 <= playergame.path_length; counter1++)
        {
            if ((counter1 % 10) == 0)
            {
                printf("%d", counter1 / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n  ");
        for (counter1 = 0; counter1 < playergame.path_length; counter1++)
        {
            printf("%d", (counter1 + 1) % 10);
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.number_of_lives, player.Treasure, playergame.number_of_moves);
        printf("+---------------------------------------------------+\n");
        if (player.number_of_lives == 0 || playergame.number_of_moves == 0)
        {
            flag1 = 2;
        }
        if
            (flag1 != 2)
        {
            flag1 = 0;
        }
        while (flag1 == 0)
        {
            printf("Next Move [1-%d]: ", playergame.path_length);
            scanf("%d", &nextmove);
            if (nextmove<1 || nextmove>playergame.path_length)
            {
                printf("  Out of Range!!!\n");
            }
            else
            {
                flag1 = 1;
            }
        }
        if (player.Player_History[nextmove - 1] == 1 && flag1 == 1)
        {
            printf("\n===============> Dope! You've been here before!\n");
        }
        if (player.Player_History[nextmove - 1] != 1 && flag1 == 1)
        {
            player.Player_History[nextmove - 1] = 1;
            playergame.number_of_moves -= 1;
            if (playergame.Bomb_location[nextmove - 1] == 1 && playergame.Treasure_location[nextmove - 1] == 1)
            {
                player.number_of_lives -= 1;
                player.Treasure += 1;
                printf("\n===============> [%c] !!! BOOOOOM !!! [%c]", hit_both, hit_both);
                printf("\n===============> [%c] $$$ Life Insurance Payout!!! [%c]\n", hit_both, hit_both);
                if (player.number_of_lives == 0)
                {
                    printf("\nNo more LIVES remaining!\n");
                }
                if (playergame.number_of_moves == 0)
                {
                    printf("\nNo more MOVES remaining!\n");
                }
            }
            else if (playergame.Bomb_location[nextmove - 1] == 1)
            {
                player.number_of_lives -= 1;
                printf("\n===============> [%c] !!! BOOOOOM !!! [%c]\n", bomb, bomb);
                if (player.number_of_lives == 0)
                {
                    printf("\nNo more LIVES remaining!\n");
                }
                if (playergame.number_of_moves == 0)
                {
                    printf("\nNo more MOVES remaining!\n");
                }
            }
            else if (playergame.Treasure_location[nextmove - 1] == 1)
            {
                player.Treasure += 1; printf("\n===============> [%c] $$$ Found Treasure! $$$ [%c]\n", treasure, treasure);
            }
            else
            {
                printf("\n===============> [%c] ...Nothing found here... [%c]\n", hit_none, hit_none);
            }
        }
    } while (flag1 != 2);
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}