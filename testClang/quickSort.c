#include <stdio.h>
#include <stdlib.h>

void quickSort(int *nums, int start, int end) {
    if (start < end) {
        int randomIndex = rand() % (end - start + 1) + start;
        if (randomIndex != start) {
            int tmp = nums[randomIndex];
            nums[randomIndex] = nums[start];
            nums[start] = tmp;
        }

        int target = nums[start], i = start, j = end, flag = 0;
        while (i < j) {
            while (i < j && (nums[j] > target || (nums[j] == target && flag == 0))) {
                if (nums[j] == target) {
                    flag = 1;
                }
                j--;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && (nums[i] < target || (nums[i] == target && flag == 1))) {
                if (nums[i] == target) {
                    flag = 0;
                }
                i++;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }

        nums[i] = target;

        quickSort(nums, start, i - 1);
        quickSort(nums, i + 1, end);
    }
}

int main() {
    int nums[10] = { 3, 3, 3, 1, 2, 1, 2, 4, 4, 10 };
    quickSort(nums, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
