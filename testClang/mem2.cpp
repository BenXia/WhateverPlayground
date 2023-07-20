#include <iostream>

int main() {
    char *a[3] = {"hello", "world", "c++"};
    char **b = a;
    char **c = {"hello", "world", "c++"};

    std::cout << a[1][1] << std::endl;
    std::cout << b[1][1] << std::endl;
    std::cout << c[1][1] << std::endl;

    return 0;
}
