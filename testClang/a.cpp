
#include <iostream>
extern "C" {
#include "b.h"
}
#include "c.hpp"

//extern "C" add(int a, int b);

//int add(int a, int b) {
//return a+b;
//}

int main() {
    int result = add(1,2);
    int maxValue = max(1,2);
    std::cout << result << " " << maxValue << std::endl;
    return 0;
}
