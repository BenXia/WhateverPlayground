#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *left = *(char **)a;
    char *right = *(char **)b;

    return strcmp(left, right);
}

int main() {
    char *a[5];
    for (int i = 0; i < 5; i++) {
        a[i] = (char *)malloc(sizeof(char) * 3);
        sprintf(a[i], "%d%d", i%3, i%2);
        a[i][2] = '\0';
    }

    qsort(a, 5, sizeof(char *), compare);

    for (int i = 0; i < 5; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}





