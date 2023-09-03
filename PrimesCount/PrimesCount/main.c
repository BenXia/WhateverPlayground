//
//  main.c
//  PrimesCount
//
//  Created by Ben on 2023/9/3.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>



// 方法一：时间复杂度高
//bool isPrimeNumber(int n) {
//    for (int i = 2; i <= sqrt(n); i++) {
//        if (n % i == 0) {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main(int argc, const char * argv[]) {
//    int n, allCount = 0;  // n 100000000
//    scanf("%d", &n);
//
//    for (int i = 2; i <= n; i++) {
//        if (isPrimeNumber(i)) {
//            allCount++;
//        }
//    }
//
//    printf("%d\n", allCount);
//
//    return 0;
//}



// 方法二：埃氏筛+bitmap，优化时间复杂度和空间复杂度
// 全局位表，第x个数 * 8 + 第y位 的位值为 1 代表是非质数， 为 0 代表是质数
// 注意，不能作为局部变量，否则会栈溢出
//static char bitMap[12500001];
//
//bool isPrimeNumber(int n) {
//    int index = n / 8;
//    int bitIndex = n % 8;
//
//    return !(bitMap[index] & (1 << bitIndex));
//}
//
//void setNotPrimeNumber(int n) {
//    int index = n / 8;
//    int bitIndex = n % 8;
//
//    bitMap[index] |= (1 << bitIndex);
//}
//
//int main(int argc, const char * argv[]) {
//    memset(bitMap, 0, sizeof(bitMap));
//
//    int n, allCount = 0;  // n 100000000
//    scanf("%d", &n);
//
//    for (int i = 2; i <= n; i++) {
//        if (isPrimeNumber(i)) {
//            for (int j = i+i; j <= n; j += i) {
//                setNotPrimeNumber(j);
//            }
//            allCount++;
//        }
//    }
//
//    printf("%d\n", allCount);
//
//    return 0;
//}



// 方法三：线性筛+bitmap（优化空间复杂度），进一步优化时间复杂度
// 全局位表，第x个数 * 8 + 第y位 的位值为 0 代表是非质数， 为 1 代表是质数
// 注意，不能作为局部变量，否则会栈溢出
static char bitMap[12500001];
static int primes[6000000];

bool isPrimeNumber(int n) {
    int index = n / 8;
    int bitIndex = n % 8;
    
    return bitMap[index] & (1 << bitIndex);
}

void setNotPrimeNumber(int n) {
    int index = n / 8;
    int bitIndex = n % 8;
    
    bitMap[index] &= (~(1 << bitIndex));
}

int main(int argc, const char * argv[]) {
    memset(bitMap, -1, sizeof(bitMap));
    memset(primes, 0, sizeof(primes));
    
    int n, allCount = 0;  // n 100000000
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        if (isPrimeNumber(i)) {
            primes[allCount++] = i;
        }

        for (int j = 0; j < allCount && primes[j] * i <= n; j++) {
            setNotPrimeNumber(primes[j] * i);

            // 因为如果 i % primes[j] == 0, 则 i / primes[j] >= 1，不妨为 k，
            // 则 k * primes[j+gap](gap > 0)  的标记设置，可以延迟等到后面 i 为 k * primes[j+gap] 的时候再设置，从而避免重复设置消耗时间
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    
    printf("%d\n", allCount);
    
    return 0;
}




