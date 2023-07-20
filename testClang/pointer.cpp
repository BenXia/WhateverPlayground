#include <iostream>

int main() {
    int a[4] = {1, 2, 3, 4};

    int *ptr1=(int *)(&a+1);

    int *ptr2=(int *)((long)a+1);

    std::cout << ptr1[-1] << std::endl << *ptr2 << std::endl;

    return 0;
}
