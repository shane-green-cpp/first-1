#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>

//random number generation function
int rando(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

struct Game{
    int win;
    int guessCount;
};

int main() {
    //* this picks random every time
    srand(time(0));
    //* instance variables
    int play = 1;
    int menuChoice;
    int max = 10;
    int num;
    int count;
    int quit = 0;
    char guess[] = "";
    int gamesPlayed = 0;
    struct Game gameResults[100];
    int fileEmpty = 0;
    //* file stuff
    FILE *fptr;
    fptr = fopen("saveMax.txt", "w+");
    if (NULL != fptr) {
    fseek (fptr, 0, SEEK_END);
    int size = ftell(fptr);

    if (0 == size) {
        fileEmpty = 1;
        putw(10, fptr);
    } else {
        max = getw(fptr);
    }
    fclose(fptr);
}

    while (quit == 0) {
        printf("press 1 to play a game\n");
        printf("press 2 to change the max number\n");
        printf("press 3 to quit\n");
        scanf(" %d", &menuChoice);
        switch(menuChoice) {
            case 1:
                num = rando(1, max);
                play = 1;
                count = 0;
                struct Game curGame;
                printf("guess away...\n");
                //* game loop
                while (play == 1) {
                    scanf(" %s", guess);
                    count++;
                    printf("%s", guess);
                    if (strcmp( guess, "q") == 0) {
                        printf("GAME ENDED\nreturning to menu...");
                        play = 0;
                        curGame.win = 0;
                        curGame.guessCount = count;
                        gameResults[gamesPlayed] = curGame;
                        gamesPlayed++;
                        break;
                    }
                    else if (atoi(guess) > num) {
                        printf("HIGH\n");
                    }
                    else if (atoi(guess) < num) {
                        printf("LOW\n");
                    }
                    else if (atoi(guess) == num) {
                        printf("YOU HAVE WON, IT TOOK %d GUESSES!!!\nreturning to menu...\n", count);
                        play = 0;
                        curGame.win = 1;
                        curGame.guessCount = count;
                        gameResults[gamesPlayed] = curGame;
                        gamesPlayed++;
                    }
                }
                break;
            case 2:
                printf("enter new max number\n");
                scanf(" %d", &max);
                if (max < 1) {
                    printf("INVALID MAX CHOICE\nMAX SET AT 10\nreturning to menu...\n");
                    max = 10;
                }
                fptr = fopen("saveMax.txt", "w+");
                putw(max, fptr);
                fclose(fptr);
                break;
            case 3:
                printf("Thank you for playing the Number Guessing Game!!!\nrecap of your games played\n");
                char winStr[] = "win";
                char loseStr[] = "loss";
                if (gamesPlayed == 0) {
                    printf("NO GAMES PLAYED\n");
                }
                for (int i = 0; i < gamesPlayed; i++) {
                    if (gameResults[i].win == 1) {
                        printf("GAME %d: %s in %d guesses\n", i+1, winStr, gameResults[i].guessCount);
                    } else {
                        printf("GAME %d: %s in %d guesses\n", i+1, loseStr, gameResults[i].guessCount);
                    }
                }
                quit = 1;
                break;
            default:
                printf("incorrect input, try again\n");
                break;
        }
    }
}