#include <stdio.h>
#include <stdbool.h>

bool different(int a, int b) {
    return a - b;
}

int main() {
    bool result = different(11, 9);

    if ((11 - 9) == true) {
        printf("(11 - 9) == true\n");
    }

    if (result == true) {
        printf("different(11 - 9) == true\n");
    }
    if (((bool)(11 - 9)) == true) {
        printf("((bool)(11 - 9)) == true\n");
    }
    printf("result=%d true=%d false=%d\n", result, true, false);

    return 0;
}
