#include <stdio.h>
#include <stdlib.h>

int guess(int num);

int guessNumber(int n){
	int min = 1;
    int max = n;

    while (min <= max) {
        int mid = min + (max - min) / 2;
        int res = guess(mid);
        if (res == 0) {
            return mid; // Correct guess
        } else if (res < 0) {
            max = mid - 1; // Guess lower
        } else {
            min = mid + 1; // Guess higher
        }
    }

    return -1; // Should never reach here if input is valid
}