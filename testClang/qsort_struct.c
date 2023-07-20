#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int age;
    char name[10];
};

int compare(const void *a, const void *b) {
    struct Student *left = (struct Student *)a;
    struct Student *right = (struct Student *)b;

    if (left->age > right->age) {
        return 1;
    } else if (left->age < right->age) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    struct Student wang = { 12, "wang" };
    struct Student liu  = { 15, "liu"  };
    struct Student zhou = { 13, "zhou" };
    struct Student guo  = { 11, "guo"  };
    struct Student ma   = { 17, "ma"   };

    struct Student a[5] = { wang, liu, zhou, guo, ma };
    //qsort(a, 5, sizeof(a[0]), compare);
    qsort(a, 5, sizeof(struct Student), compare);
    for (int i = 0; i < 5; i++) {
        printf("%d %s\n", a[i].age, a[i].name);
    }
    return 0;
}
