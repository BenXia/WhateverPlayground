#include <stdlib.h>
#include <stdio.h>

int main() {
    char **a = {"hello", "world", "c++"};

    printf("%s\n", a);
    printf("%c\n", a[0]);
    printf("%c\n", a[1]);
    printf("%c\n", a[1][1]); 

    return 0;
}
