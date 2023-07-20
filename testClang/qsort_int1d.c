#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *left = (int *)a;
    int *right = (int *)b;

    if (*left > *right) {
        return 1;
    } else if (*left < *right) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int a[5] = { 5, 3, 1, 2, 4 };
    qsort(a, 5, sizeof(int), compare);
    //qsort(a, 5, sizeof(a[0]), compare);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
