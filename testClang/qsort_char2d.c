#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    static int s_number = 0;

    if (s_number == 0) {
        s_number = 1;
        printf("a:%p, b:%p\n", a, b);
        printf("a[0]:%c, b[0]:%c\n", ((char *)a)[0], ((char *)b)[0]);
        printf("a[1]:%c, b[1]:%c\n", ((char *)a)[1], ((char *)b)[1]);

        char *left = *(char (*)[3])a;
        char *right = *(char (*)[3])b;
        printf("left:%p, right:%p\n", left, right);
        printf("left[0]:%c, right[0]:%c\n", left[0], right[0]);
        printf("left[1]:%c, right[1]:%c\n", left[1], right[1]);
    }

    //char *left = *(char (*)[3])a;
    //char *right = *(char (*)[3])b;
    //char *left = (char *)((char (*)[3])a);
    //char *right = (char *)((char (*)[3])b);
    char *left = (char *)a;
    char *right = (char *)b;

    return strcmp(left, right);
}

int main() {
    char a[5][3] = {"eb","ea","ab","di","bc"};
    printf("sizeof(a[0]): %lu\n", sizeof(a[0]));
    printf("sizeof(char[3]): %lu\n", sizeof(char[3]));

    qsort(a, 5, sizeof(a[0]), compare);
    //qsort(a, 5, sizeof(char[3]), compare);
    //�����д���Ǵ����
    //qsort(a, 5, sizeof(char (*)[3]), compare);
    for (int i = 0; i < 5; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}





