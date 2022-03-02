#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int count = 0;
    int quit = 0;
    int guess = -1;

    while (quit == 0) {
        printf("press 1 to play a game\n");
        printf("press 2 to change the max number\n");
        printf("press 3 to quit\n");
        scanf(" %d", &menuChoice);
        switch(menuChoice) {
            case 1:
                num = rando(1, max);
                play = 1;
                //* game loop
                while (play == 1) {
                    scanf(" %d", &guess);
                    count++;
                    printf("%d", guess);
                    if (guess == -1) {
                        printf("GAME ENDED\nreturning to menu...");
                        play = 0;
                    }
                    else if ((int)guess > num) {
                        printf("HIGH\n");
                        guess = -1;
                    }
                    else if ((int)guess < num) {
                        printf("LOW\n");
                        guess = -1;
                    }
                    else if ((int)guess == num) {
                        printf("YOU HAVE WON, IT TOOK %d GUESSES!!!\nreturning to menu...\n", count);
                        play = 0;
                    }
                }
                break;
            case 2:
                printf("enter new max number\n");
                scanf(" %d", &max);
                break;
            case 3:
                printf("Thank you for playing the Number Guessing Game!!!");
                quit = 1;
                break;
            default:
                printf("incorrect input, try again\n");
                break;
        }
    }
}