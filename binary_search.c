# include <stdio.h>
# include <stdlib.h>


int search(int* nums, int numsSize, int target) {
    int min = 0;
    int max = numsSize - 1;
    while (min <= max) {
        int mid = min + (max - min) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return -1;
}