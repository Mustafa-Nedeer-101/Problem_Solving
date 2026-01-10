#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool binarySearch(int* arr, int size, int target, int skipIndex) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            if (mid != skipIndex)
                return true;
            // target found at same index, search neighbors
            int l = mid - 1, r = mid + 1;
            while (l >= 0 && arr[l] == target) {
                if (l != skipIndex) return true;
                l--;
            }
            while (r < size && arr[r] == target) {
                if (r != skipIndex) return true;
                r++;
            }
            return false;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);

    for (int i = 0; i < arrSize; i++) {
        int target = 2 * arr[i];

        if (binarySearch(arr, arrSize, target, i))
            return true;
    }

    return false;
}
