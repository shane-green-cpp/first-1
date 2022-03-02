#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//random number generation function
int rando(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main(int argc, char **argv) {
    //* this picks random every time
    srand(time(0));
    // * salad, soup, sandwich, pizza
    double cost[] = {9.95, 4.55, 13.25, 22.35};
    int item = rando(0, 3);
    printf("rando %d", item);

}