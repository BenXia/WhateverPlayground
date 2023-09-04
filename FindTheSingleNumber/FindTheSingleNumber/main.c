//
//  main.c
//  FindTheSingleNumber
//
//  Created by Ben on 2023/9/4.
//

#include <stdio.h>
#include <stdlib.h>

int getTheSingleNumber(int *nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    int n;
    printf("请输入数字个数：");
    scanf("%d", &n);
    
    while (n <= 0 || n % 2 == 0 || n >= 1000) {
        printf("输入必须为大于0并小于1000的奇数\n请重新输入：");
        scanf("%d", &n);
    }
    
    int *nums = (int *)malloc((size_t)(sizeof(int) * n));
    
    printf("请输入%d个数，用空格隔开即可：\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("唯一数是: %d\n", getTheSingleNumber(nums, n));
    
    free(nums);
    
    return 0;
}



