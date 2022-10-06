#include "reverse.h"
#include "truncate.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define ITERATIONS 55

const char* pacman_open[] = {
    "   .--.   ",
    "  / _.-'  ",
    "  \\  '-.  ",
    "   '--'   " };

const char* pacman_closed[] = {
    "   .--.   ",
    "  /  __\\  ",
    "  \\    /  ",
    "   '--'   " };

const char* ghost[] = {
    "   .-.   ",
    "  | OO|  ",
    "  |   |  ",
    "  '^^^'  " };

int main(int argc, char** argv)
{
    char line[256] = "";
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < ITERATIONS; i++) {
        for (int j = 0; j < 4; j++) {
	    line[0] = '\0';
	    for (int spaces = 0; spaces <= i; spaces++) {
		strcat(line, " ");
	    }
	    if (i % 2 == 0) {
		strcat(line, pacman_open[j]);
	    }
	    else {
		strcat(line, pacman_closed[j]);
	    }
	    strcat(line, " ");
	    for (int i = 0; i < 3; i++) {
		strcat(line, ghost[j]);
		strcat(line, " ");
	    }
	    printf("%s\n", strtrunc(line, 55));
	}
	usleep(100*1000);
	printf("\e[1;1H\e[2J");
    }
    return 0;
}

