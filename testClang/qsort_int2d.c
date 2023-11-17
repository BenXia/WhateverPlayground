#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    static int s_number = 0;

    if (s_number == 0) {
        s_number = 1;

        printf("a:%p, b:%p\n", a, b);
        // 注意这边的指针实际类型是 (int *)[2] 则不能写成 ((*)(int **)a)[0]
        // 如果指针实际类型是 (int **) 则可以写成 ((*)(int **)a)[0]
        // (int *)[2] 类型的指针和 (int **) 类型的指针不能随意互相转换。
        //(特殊情况下可以把 (int *)[2] 直接转成 int * 类型，因为两者地址值是一样的，只是类型不一样）
        printf("a[0]:%d, b[0]:%d\n", ((int *)a)[0], ((int *)b)[0]);
        printf("a[1]:%d, b[1]:%d\n", ((int *)a)[1], ((int *)b)[1]);

        int *left = *(int (*)[2])a;
        int *right = *(int (*)[2])b;

        printf("left:%p, right:%p\n", left, right);
        printf("left[0]: %d, right[0]: %d\n", left[0], right[0]);
        printf("left[1]: %d, right[1]: %d\n", left[1], right[1]);
    }

    int *left = *(int (*)[2])a;
    int *right = *(int (*)[2])b;

    //printf("%d %d %d %d\n", left[0], left[1], right[0], right[1]);
    if (left[0] > right[0]) {
        return 1;
    } else if (left[0] < right[0]) {
        return -1;
    } else {
        if (left[1] > right[1]) {
            return 1;
        } else if (left[1] < right[1]) {
            return -1;
        } else {
            return 0;
        }
    }
}

int main() {
    int a[5][2] = {{5,4},{5,1},{5,5},{5,3},{5,2}};
    printf("sizeof(a[0]): %lu\n", sizeof(a[0]));
    printf("sizeof(int[2]): %lu\n", sizeof(int (*)[2]));
    printf("sizeof(int[2]): %lu\n", sizeof(int[2]));
    printf("sizeof(int[3]): %lu\n", sizeof(int (*)[3]));
    printf("sizeof(int[3]): %lu\n", sizeof(int[3]));

    //qsort(a, 5, sizeof(a[0]), compare);
    //qsort(a, 5, sizeof(int[2]), compare);
    //下面的写法是错误的,只是恰巧等于指针长度8=2*4
    qsort(a, 5, sizeof(int (*)[2]), compare);
    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", a[i][0], a[i][1]);
    }
    return 0;
}
