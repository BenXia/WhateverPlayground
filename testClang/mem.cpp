#include <iostream>

struct testSA {
    char a;
};

struct testSB {
    struct testSA b;
};

int main() {
    int **a[3][4], b[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int **v = (int **)b;
    int (*k)[4] = (int (*)[4])b;
    char c[] = "hello world";
    char *p = c;

    std::cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(v) << " " << sizeof(c) << " " << sizeof(p) << std::endl;
    std::cout << *(*(k+1)) << std::endl;
    std::cout << v << " " << b << " " << &b[0][0] << std::endl;
    std::cout << *v << " " << *b << std::endl;
    std::cout << v + 1 << " " << *(v + 1)  << std::endl;


    int x[5] = { 1, 2, 3, 4, 5 };
    int *ptr = (int *)(&x + 1);
    std::cout << *(x + 3) << std::endl << *(ptr-3) << std::endl;


    struct testSA sa;
    struct testSB sb;
    std::cout << sizeof(sa) << " " << sizeof(sb) << std::endl;


    return 0;
}
