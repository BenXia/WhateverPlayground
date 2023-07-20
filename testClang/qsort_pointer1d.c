#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *p1 = *(char **)a;
    char *p2 = *(char **)b;

    return strcmp(p1, p2);
}

int main() {
    char arr1[5] = "abc";
    char arr2[5] = "bcd";
    char arr3[5] = "cdf";
    char arr4[5] = "gnm";
    char arr5[5] = "caz";

    char *arr[5] = { arr1, arr2, arr3, arr4, arr5 };

    qsort(arr, 5, sizeof(char *), compare);

    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}





