#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//random number generation function
int rando(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    //* this picks random every time
    srand(time(0));
    int play = 1;
    int max = 10;
    int count = 0;
    int num = rando(1, max);
    int guess = -1;

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
}