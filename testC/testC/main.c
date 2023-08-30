//
//  main.c
//  testC
//
//  Created by Ben on 2023/6/2.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//char *intToStr(int x) {
//    // 正数或负数都只将后面部分变成字符串
//    int flag = 1;
//    if (x < 0) {
//        flag = -1;
//    }
//
//    char r[15] = "";
//    int rIndex = 0;
//    int v = x;
//    while (v != 0) {
//        r[rIndex++] = (v % 10) * flag + '0';
//        v = v / 10;
//    }
//    r[rIndex] = '\0';
//
//    char *result = (char *)malloc(sizeof(char) * (rIndex + 1));
//    for (int i = 0; i < rIndex; i++) {
//        result[rIndex - 1 - i] = r[i];
//    }
//    result[rIndex] = '\0';
//
//    return result;
//}
//
//int strToInt(char *str, int signFlag) {
//    if (str == NULL || strlen(str) == 0) {
//        return 0;
//    }
//
//    int sLen = strlen(str);
//    int result = 0;
//    for (int i = 0; i < sLen; i++) {
//        result = result * 10 + (str[i] - '0') * signFlag;
//    }
//
//    return result;
//}
//
//int compareStr(char *str1, char *str2) {
//    int s1Len = strlen(str1), s2Len = strlen(str2);
//
//    if (s1Len > s2Len) {
//        return 1;
//    } else if (s1Len < s2Len) {
//        return -1;
//    } else {
//        return strcmp(str1, str2);
//    }
//}
//
//int reverse(int x) {
//    int maxV = 0x7FFFFFFF;
//    int signFlag = 1;
//    if (x < 0) {
//        maxV = ~(0x7FFFFFFF);
//        signFlag = -1;
//    }
//
//    char *reverseXStr = intToStr(x);
//    char *maxXStr = intToStr(maxV);
//
//    int reverseXStrLen = strlen(reverseXStr);
//    int halfLen = reverseXStrLen / 2;
//    char tmp = '\0';
//    for (int i = 0; i < halfLen; i++) {
//        tmp = reverseXStr[i];
//        reverseXStr[i] = reverseXStr[reverseXStrLen - 1 - i];
//        reverseXStr[reverseXStrLen - 1 - i] = tmp;
//    }
//
//    if (compareStr(reverseXStr, maxXStr) > 0) {
//        free(reverseXStr);
//        free(maxXStr);
//        return 0;
//    } else {
//        int result = strToInt(reverseXStr, signFlag);
//        free(reverseXStr);
//        free(maxXStr);
//        return result;
//    }
//}











//int divide(int dividend, int divisor) {
//    int flag = 1, result = 0, i = 1;
//    if (divisor == INT32_MIN) {
//        if (dividend == INT32_MIN) {
//            return 1;
//        } else {
//            return 0;
//        }
//    }
//    if (dividend == INT32_MIN) {
//        if (divisor == -1) {
//            return INT32_MAX;
//        } else if (divisor > 0) {
//            if (divisor == 1) {
//                return INT32_MIN;
//            } else {
//                dividend += divisor;
//                result += 1;
//            }
//        } else if (divisor < 0) {
//            if (divisor == -1) {
//                return INT32_MAX;
//            } else {
//                dividend -= divisor;
//                result += 1;
//            }
//        }
//    }
//
//    int uDividend = dividend, uDivisor = divisor;
//    if (dividend < 0) {
//        uDividend = -dividend;
//        flag = -flag;
//    }
//    if (divisor < 0) {
//        uDivisor = -divisor;
//        flag = -flag;
//    }
//
//    int lastDivisor = uDivisor, lastDividend = uDividend;
//
//    while (lastDivisor < (uDividend >> 1)) {
//        lastDivisor <<= 1;
//        i <<= 1;
//    }
//
//    while (lastDivisor != 0 && lastDividend != 0) {
//        while (lastDividend >= lastDivisor) {
//            lastDividend -= lastDivisor;
//            result += i;
//        }
//
//        lastDivisor >>= 1;
//        i >>= 1;
//    }
//
//    return result * flag;
//}












//#define kMaxKeySize 100
//
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//
//struct HashNode {
//    int key;
//    struct ListNode *val;
//    struct HashNode *next;
//};
//
//static struct HashNode *gTable[kMaxKeySize];
//
//int getHash(int key) {
//    if (key < 0) {
//        return -key % kMaxKeySize;
//    } else {
//        return key % kMaxKeySize;
//    }
//}
//
//void hashPut(int key, struct ListNode *val) {
//    int hashKey = getHash(key);
//    if (gTable[hashKey] != NULL) {
//        struct HashNode *node = gTable[hashKey];
//        while (node != NULL && node->key != key) {
//            node = node->next;
//        }
//        if (node != NULL) {
//            node->val = val;
//            return;
//        }
//    }
//
//    struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));
//    newNode->key = key;
//    newNode->val = val;
//    newNode->next = gTable[hashKey];
//
//    gTable[hashKey] = newNode;
//}
//
//struct ListNode *hashGet(int key) {
//    int hashKey = getHash(key);
//    if (gTable[hashKey] != NULL) {
//        struct HashNode *node = gTable[hashKey];
//        while (node != NULL && node->key != key) {
//            node = node->next;
//        }
//        if (node != NULL) {
//            return node->val;
//        }
//    }
//
//    return NULL;
//}
//
//struct ListNode* removeZeroSumSublists(struct ListNode* head) {
//    if (head == NULL) {
//        return head;
//    }
//
//    struct ListNode *p = head;
//    int prefixSum = 0;
//    while (p != NULL) {
//        prefixSum += p->val;
//        hashPut(prefixSum, p);
//
//        p = p->next;
//    }
//
//    struct ListNode *newHead = NULL;
//
//    if (hashGet(0) == NULL) {
//        newHead = head;
//        p = head;
//        prefixSum = 0;
//    } else {
//        newHead = hashGet(0)->next;
//        p = newHead;
//        prefixSum = 0;
//    }
//
//    while (p != NULL) {
//        prefixSum += p->val;
//
//        if (hashGet(prefixSum) != NULL) {
//            p->next = hashGet(prefixSum)->next;
//            p = p->next;
//        } else {
//            p = p->next;
//        }
//    }
//
//    return newHead;
//}
//
//
//
//void nextPermutation(int* nums, int numsSize) {
//    if (nums == NULL || numsSize <= 1) {
//        return;
//    }
//
//    int i = numsSize - 2, left = 0, tmp;
//    while (i >= 0) {
//        if (nums[i] < nums[i+1]) {
//            int j = i + 1;
//            for (; j < numsSize; j++) {
//                if (nums[j] > nums[i]) {
//                } else {
//                    break;
//                }
//            }
//
//            j--;
//
//            tmp = nums[i];
//            nums[i] = nums[j];
//            nums[j] = tmp;
//
//            left = i + 1;
//            break;
//        } else {
//            i--;
//        }
//    }
//
//    int right = numsSize - 1;
//    while (left < right) {
//        tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//
//        left++;
//        right--;
//    }
//}












bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int hash[3][boardSize][boardSize];
    memset(hash, 0, sizeof(hash));

    int v, k;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            v = board[i][j] - '0' - 1;

            if (v >= 0 && v <= 8) {
                hash[0][i][v] += 1;
                hash[1][j][v] += 1;

                k = (i / 3) * 3 + (j / 3);
                hash[2][k][v] += 1;

                if (hash[0][i][v] > 1) {
                    return false;
                }
                if (hash[1][j][v] > 1) {
                    return false;
                }
                if (hash[2][k][v] > 1) {
                    return false;
                }
            }
        }
    }

    return true;
}



void dfsRecursive(int **grid, int **visited, int *opened, int row, int col, int rows, int cols, int islandCount) {
    visited[row][col] = islandCount;

    if (row > 0 && grid[row-1][col] == 0 && visited[row-1][col] == 0) {
        dfsRecursive(grid, visited, opened, row-1, col, rows, cols, islandCount);
    } else if (row == 0) {
        opened[islandCount] = 1;
    }
    if (col > 0 && grid[row][col-1] == 0 && visited[row][col-1] == 0) {
        dfsRecursive(grid, visited, opened, row, col-1, rows, cols, islandCount);
    } else if (col == 0) {
        opened[islandCount] = 1;
    }
    if (row < rows - 1 && grid[row+1][col] == 0 && visited[row+1][col] == 0) {
        dfsRecursive(grid, visited, opened, row+1, col, rows, cols, islandCount);
    } else if (row == rows-1) {
        opened[islandCount] = 1;
    }
    if (col < cols - 1 && grid[row][col+1] == 0 && visited[row][col+1] == 0) {
        dfsRecursive(grid, visited, opened, row, col+1, rows, cols, islandCount);
    } else if (col == cols - 1) {
        opened[islandCount] = 1;
    }
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0 || (*gridColSize) == 0) {
        return 0;
    }

    int rows = gridSize, cols = *gridColSize;
    int **visited = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        visited[i] = (int *)malloc(sizeof(int) * cols);
        memset(visited[i], 0, sizeof(int) * cols);
    }
    int *opened = (int *)malloc(sizeof(int) * 5001);
    memset(opened, 0, sizeof(int) * 5001);
    int islandCount = 0, lockIslandCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0 && visited[i][j] == 0) {
                islandCount += 1;

                dfsRecursive(grid, visited, opened, i, j, rows, cols, islandCount);
            }
        }
    }
    for (int i = 1; i <= islandCount; i++) {
        if (opened[i] == 0) {
            lockIslandCount += 1;
        }
    }

    for (int i = 0; i < rows; i++) {
        free(visited[i]);
    }
    free(visited);
    free(opened);

    return lockIslandCount;
}









int min(int a, int b) {
    return a > b ? b : a;
}

int connectTwoGroups(int** cost, int costSize, int* costColSize) {
    if (cost == NULL || costSize == 0 || costColSize == NULL || *costColSize == 0) {
        return 0;
    }

    int lSize = costSize, rSize = *costColSize, lMax = 1<<lSize, rMax = 1<<rSize;
    int dp[4][4];
    for (int i = 0; i < lMax; i++) {
        for (int j = 0; j < rMax; j++) {
            dp[i][j] = INT16_MAX;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < lSize; i++) {
        for (int j = 0; j < rSize; j++) {
            dp[1<<i][1<<j] = cost[i][j];
        }
    }

    for (int i = 1; i < lMax; i++) {
        for (int j = 1; j < rMax; j++) {
            for (int k = 0; k < lSize; k++) {
                if ((1<<k) & i) {
                    for (int l = 0; l < rSize; l++) {
                        if ((1<<l) & j) {
                            if (((1<<k) ^ i) != 0 || ((1<<l) ^ j) != 0) {
                                //for (int k = 0; k < lSize; k++) {
                                //if (((1<<k) & i) && ((1<<k) ^ i) != 0) {
                                //                            for (int l = 0; l < rSize; l++) {
                                //                                if (((1<<l) & j) && ((1<<l) ^ j) != 0) {
                                dp[i][j] = min(dp[i][j], cost[k][l] + min(dp[(1<<k) ^ i][j], dp[i][(1<<l) ^ j]));
                                //}
                                if (((1<<k) ^ i) != 0 && ((1<<l) ^ j) != 0) {
                                    dp[i][j] = min(dp[i][j], cost[k][l] + dp[(1<<k) ^ i][(1<<l) ^ j]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return dp[lMax-1][rMax-1];
}







int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    if (intervals == NULL || intervalsSize == 0 || *intervalsColSize == 0) {
        *returnSize = 1;
        *returnColumnSizes = (int *)malloc(sizeof(int) * 1);
        int **result = (int **)malloc(sizeof(int *) * 1);
        int *item = (int *)malloc(sizeof(int) * 2);
        item[0] = newInterval[0];
        item[1] = newInterval[1];
        result[0] = item;
        (*returnColumnSizes)[0] = 2;
        return result;
    }

    int left = 0, right = intervalsSize - 1, lastRight = intervalsSize, mid;
    while (left <= right) {
        mid = (left + right) / 2;

        if (intervals[mid][0] >= newInterval[0]) {
            lastRight = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    int beforeCount = 0, afterCount = 0;
    int *newItem = (int *)malloc(sizeof(int) * 2);
    newItem[0] = newInterval[0];
    newItem[1] = newInterval[1];

    if (lastRight - 1 >= 0) {
        if (intervals[lastRight-1][1] >= newInterval[0]) {
            beforeCount = lastRight - 2 + 1;
            newItem[0] = intervals[lastRight-1][0];
        } else {
            beforeCount = lastRight;
        }
    } else {
        beforeCount = 0;
    }

    int index = lastRight - 1;
    if (index < 0) {
        index = 0;
    }
    while (index < intervalsSize) {
        if (intervals[index][0] > newInterval[1]) {
            afterCount = intervalsSize - index;
            break;
        } else if (intervals[index][1] >= newInterval[1]) {
            newItem[1] = intervals[index][1];
            afterCount = intervalsSize - index - 1;
            break;
        } else {
            index++;
        }
    }

    int **result = (int **)malloc(sizeof(int *) * (beforeCount + afterCount + 1));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (beforeCount + afterCount + 1));
    *returnSize = beforeCount + afterCount + 1;
    for (int i = 0; i < beforeCount + afterCount + 1; i++) {
        (*returnColumnSizes)[i] = 2;
        if (i < beforeCount) {
            int *subItem = (int *)malloc(sizeof(int) * 2);
            subItem[0] = intervals[i][0];
            subItem[1] = intervals[i][1];
            result[i] = subItem;
        } else if (i == beforeCount) {
            result[i] = newItem;
        } else {
            int *subItem = (int *)malloc(sizeof(int) * 2);
            subItem[0] = intervals[intervalsSize - afterCount + i - beforeCount - 1][0];
            subItem[1] = intervals[intervalsSize - afterCount + i - beforeCount - 1][1];
            result[i] = subItem;
        }
    }

    return result;
}


int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(result, 0, sizeof(int) * (digitsSize + 1));
    int carry = 1, index = digitsSize - 1, v = 0, rIndex = 0;

    while (index >= 0 || carry != 0) {
        v = carry;
        if (index >= 0) {
            v += digits[index];
        }

        if (v >= 10) {
            carry = 1;
            v -= 10;
        } else {
            carry = 0;
        }

        result[rIndex] = v;

        index--;
        rIndex++;
    }

    int halfRLen = rIndex / 2, tmp;
    for (int i = 0; i < halfRLen; i++) {
        tmp = result[i];
        result[i] = result[rIndex - 1 - i];
        result[rIndex - 1 - i] = tmp;
    }

    *returnSize = rIndex;
    return result;
}






bool hashLargerThan(int lHash[125], int rHash[125]) {
    for (int i = 0; i < 125; i++) {
        if (lHash[i] < rHash[i]) {
            return false;
        }
    }

    return true;
}

char * minWindow(char * s, char * t) {
    int sLen = strlen(s), tLen = strlen(t);
    if (sLen < tLen) {
        char *result = (char *)malloc(sizeof(char) * 1);
        result[0] = '\0';
        return result;
    }

    int tHash[125] = { 0 }, sHash[125] = { 0 };
    char ch;
    for (int i = 0; i < tLen; i++) {
        ch = t[i];
        tHash[(unsigned char)ch] += 1;
    }
    int sIndexes[sLen];
    int sAllLen = 0;
    for (int i = 0; i < sLen; i++) {
        ch = s[i];
        if (tHash[(unsigned char)ch] > 0) {
            sIndexes[sAllLen++] = i;
        }
    }

    int left = -1, minLen = sLen + 1, minLenLeft = 0, minLenRight = 0;
    for (int i = 0; i < sAllLen; i++) {
        if (left == -1) {
            left = i;
        }
        ch = s[sIndexes[i]];
        sHash[(unsigned char)ch] += 1;

        for (int j = left; j <= i; j++)  {
            ch = s[sIndexes[j]];
            if (sHash[(unsigned char)ch] > tHash[(unsigned char)ch]) {
                sHash[(unsigned char)ch] -= 1;
                continue;
            } else {
                left = j;
                break;
            }
        }

        if (hashLargerThan(sHash, tHash)) {
            if (sIndexes[i] - sIndexes[left] + 1 < minLen) {
                minLen = sIndexes[i] - sIndexes[left] + 1;
                minLenLeft = sIndexes[left];
                minLenRight = sIndexes[i];
            }
        }
    }

    if (minLen == sLen + 1) {
        char *result = (char *)malloc(sizeof(char) * 1);
        result[0] = '\0';
        return result;
    } else {
        char *result = (char *)malloc(sizeof(char) * (minLen + 1));
        for (int i = minLenLeft; i <= minLenRight; i++) {
            result[i - minLenLeft] = s[i];
        }
        result[minLen] = '\0';
        return result;
    }
}



int* grayCode(int n, int* returnSize) {
    int allCount = 1<<n;
    *returnSize = allCount;

    int *result = (int *)malloc(sizeof(int) * allCount);
    memset(result, 0, sizeof(int) * allCount);
    result[0] = 0;

    int hash[1<<n];
    memset(hash, 0, sizeof(hash));
    hash[0] = 1;
    
    int stack[1<<n];
    memset(stack, 0, sizeof(stack));
    for (int i = 0; i < allCount; i++) {
        stack[i] = -1;
    }

    int sTop = 1;
    *returnSize = allCount;

    int lastResult, lastStackV, v;
    
    while (sTop > 0) {
        lastResult = result[sTop - 1];
        lastStackV = stack[sTop - 1];
        lastStackV += 1;
        stack[sTop - 1] = lastStackV;

        if (lastStackV >= n) {
            stack[sTop - 1] = -1;
            result[sTop - 1] = 0;
            sTop--;
        } else {
            v = lastResult ^ (1<<lastStackV);

            if (hash[v] > 0) {
                continue;
            } else {
                hash[v] = 1;

                if (sTop == allCount - 1) {
                    int value = v, oneCount = 0;
                    while (value > 0) {
                        oneCount += 1;
                        value = value & (value - 1);
                    }

                    if (oneCount == 1) {
                        result[sTop] = v;
                        break;
                    } else {
                        stack[sTop - 1] = -1;
                        result[sTop - 1] = 0;
                        sTop--;
                    }
                } else {
                    result[sTop] = v;
                    stack[sTop] = -1;
                    sTop++;
                }
            }
        }
    }

    return result;
}




char *reverse(char *in) {
    if (in == NULL) {
        return NULL;
    }

    char *out = (char *)malloc(sizeof(char) * (strlen(in) + 1));
    strcpy(out, in);
    int sLen = strlen(in), halfLen = sLen / 2;
    char tmp = '\0';
    for (int i = 0; i < halfLen; i++) {
        tmp = out[i];
        out[i] = out[sLen - 1 - i];
        out[sLen - 1 - i] = tmp;
    }

    return out;
}

char * addStrings(char * num1, char * num2) {
    if (num1 == NULL && num2 == NULL) {
        char *result = (char *)malloc(sizeof(char) * 2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    } else if (num1 == NULL) {
        char *result = (char *)malloc(sizeof(char) * (strlen(num2) + 1));
        strcpy(result, num2);
        return result;
    } else if (num2 == NULL) {
        char *result = (char *)malloc(sizeof(char) * (strlen(num1) + 1));
        strcpy(result, num1);
        return result;
    }

    int s1Len = strlen(num1), s2Len = strlen(num2), rLen = s1Len + s2Len + 2;
    char *result = (char *)malloc(sizeof(char) * rLen);
    memset(result, 0, sizeof(char) * rLen);

    char *r1 = reverse(num1), *r2 = reverse(num2);
    int carry = 0, rIndex = 0, v = 0;
    while (carry != 0 || rIndex < s1Len || rIndex < s2Len) {
        v = carry;

        if (rIndex < s1Len) {
            v = v + (r1[rIndex] - '0');
        }
        if (rIndex < s2Len) {
            v = v + (r2[rIndex] - '0');
        }

        if (v >= 10) {
            carry = 1;
            v -= 10;
        } else {
            carry = 0;
        }

        result[rIndex++] = v + '0';
    }
    if (rIndex == 0) {
        result[rIndex++] = '0';
    }

    result = (char *)realloc(result, sizeof(char) * (rIndex + 1));
    char *finalResult = reverse(result);
    free(r1);
    free(r2);
    free(result);

    return finalResult;
}


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int maxResultSize = 10;
    int **result = (int **)malloc(sizeof(int *) * maxResultSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * maxResultSize);
    *returnSize = 0;

    int row[2001], rIndex = 0;

    struct TreeNode *queue[4001] = { root, NULL }, *p = NULL;
    int front = 0, tail = 2;
    while (front < tail) {
        p = queue[front++];

        if (p == NULL) {
            if (*returnSize >= maxResultSize) {
                maxResultSize += 10;
                result = (int **)realloc(result, sizeof(int *) * maxResultSize);
                *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * maxResultSize);
            }

            int *subResult = (int *)malloc(sizeof(int) * rIndex);
            for (int i = 0; i < rIndex; i++) {
                subResult[i] = row[i];
            }
            result[*returnSize] = subResult;
            (*returnColumnSizes)[*returnSize] = rIndex;
            (*returnSize) += 1;

            rIndex = 0;

            if (front == tail) {
                break;
            } else {
                queue[tail++] = NULL;
            }
        } else {
            row[rIndex++] = p->val;

            if (p->left) {
                queue[tail++] = p->left;
            }
            if (p->right) {
                queue[tail++] = p->right;
            }
        }
    }

    int halfLen = (*returnSize) / 2, allLen = *returnSize;
    int *tmp = NULL, tempLen = 0;
    for (int i = 0; i < halfLen; i++) {
        tmp = result[i];
        result[i] = result[allLen - 1 - i];
        result[allLen - 1 - i] = tmp;
        
        tempLen = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[allLen - 1 - i];
        (*returnColumnSizes)[allLen - 1 - i] = tempLen;
    }
    return result;
}


static int minHeap[100001][3];
static int heapIndex = 0;

void insertToMinHeap(int length, int left, int right) {
    minHeap[heapIndex][0] = length;
    minHeap[heapIndex][1] = left;
    minHeap[heapIndex][2] = right;

    heapIndex++;

    int childIndex = heapIndex - 1, parentIndex = 0, temp0, temp1, temp2;

    while (childIndex > 0) {
        parentIndex = (childIndex - 1) / 2;
        if (minHeap[childIndex][0] < minHeap[parentIndex][0]) {
            temp0 = minHeap[childIndex][0];
            temp1 = minHeap[childIndex][1];
            temp2 = minHeap[childIndex][2];
            minHeap[childIndex][0] = minHeap[parentIndex][0];
            minHeap[childIndex][1] = minHeap[parentIndex][1];
            minHeap[childIndex][2] = minHeap[parentIndex][2];
            minHeap[parentIndex][0] = temp0;
            minHeap[parentIndex][1] = temp1;
            minHeap[parentIndex][2] = temp2;

            childIndex = parentIndex;
        } else {
            break;
        }
    }
}

void removeMinHeapTop() {
    if (heapIndex == 0) {
        return;
    }
    if (heapIndex == 1) {
        heapIndex -= 1;
        return;
    }

    minHeap[0][0] = minHeap[heapIndex - 1][0];
    minHeap[0][1] = minHeap[heapIndex - 1][1];
    minHeap[0][2] = minHeap[heapIndex - 1][2];
    heapIndex -= 1;

    int parentIndex = 0, childIndex = 0, temp0, temp1, temp2;

    while (parentIndex * 2 + 1 < heapIndex) {
        childIndex = parentIndex * 2 + 1;
        if ((childIndex + 1 < heapIndex) && (minHeap[childIndex+1][0] < minHeap[childIndex][0])) {
            childIndex += 1;
        }

        if (minHeap[childIndex][0] < minHeap[parentIndex][0]) {
            temp0 = minHeap[childIndex][0];
            temp1 = minHeap[childIndex][1];
            temp2 = minHeap[childIndex][2];
            minHeap[childIndex][0] = minHeap[parentIndex][0];
            minHeap[childIndex][1] = minHeap[parentIndex][1];
            minHeap[childIndex][2] = minHeap[parentIndex][2];
            minHeap[parentIndex][0] = temp0;
            minHeap[parentIndex][1] = temp1;
            minHeap[parentIndex][2] = temp2;

            parentIndex = childIndex;
        } else {
            break;
        }
    }
}

void quickSortQueries(int (*queriesArray)[2], int start, int end) {
    if (start < end) {
        int randomIndex = rand() % (end - start + 1) + start;
        if (randomIndex != start) {
            int temp0 = queriesArray[start][0], temp1 = queriesArray[start][1];
            queriesArray[start][0] = queriesArray[randomIndex][0];
            queriesArray[start][1] = queriesArray[randomIndex][1];
            queriesArray[randomIndex][0] = temp0;
            queriesArray[randomIndex][1] = temp1;
        }

        int target[2] = {queriesArray[start][0], queriesArray[start][1]}, i = start, j = end;
        while (i < j) {
            while (i < j && queriesArray[j][0] > target[0]) {
                j--;
            }
            if (i < j) {
                queriesArray[i][0] = queriesArray[j][0];
                queriesArray[i][1] = queriesArray[j][1];
                i++;
            }
            while (i < j && queriesArray[i][0] <= target[0]) {
                i++;
            }
            if (i < j) {
                queriesArray[j][0] = queriesArray[i][0];
                queriesArray[j][1] = queriesArray[i][1];
                j--;
            }
        }

        queriesArray[i][0] = target[0];
        queriesArray[i][1] = target[1];

        quickSortQueries(queriesArray, start, i - 1);
        quickSortQueries(queriesArray, i + 1, end);
    }
}

void quickSortIntervals(int **intervals, int start, int end) {
    if (start < end) {
        int randomIndex = rand() % (end - start + 1) + start;
        if (randomIndex != start) {
            int temp0 = intervals[start][0], temp1 = intervals[start][1];
            intervals[start][0] = intervals[randomIndex][0];
            intervals[start][1] = intervals[randomIndex][1];
            intervals[randomIndex][0] = temp0;
            intervals[randomIndex][1] = temp1;
        }

        int target[2] = {intervals[start][0], intervals[start][1]}, i = start, j = end;
        while (i < j) {
            while (i < j && intervals[j][0] > target[0]) {
                j--;
            }
            if (i < j) {
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
                i++;
            }
            while (i < j && intervals[i][0] <= target[0]) {
                i++;
            }
            if (i < j) {
                intervals[j][0] = intervals[i][0];
                intervals[j][1] = intervals[i][1];
                j--;
            }
        }

        intervals[i][0] = target[0];
        intervals[i][1] = target[1];

        quickSortIntervals(intervals, start, i - 1);
        quickSortIntervals(intervals, i + 1, end);
    }
}

int* minInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* queries, int queriesSize, int* returnSize) {
    heapIndex = 0;
    
    if (queries == NULL || queriesSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int *)malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    int queriesArray[queriesSize][2];
    for (int i = 0; i < queriesSize; i++) {
        queriesArray[i][0] = queries[i];
        queriesArray[i][1] = i;
    }

    quickSortQueries(queriesArray, 0, queriesSize - 1);

    quickSortIntervals(intervals, 0, intervalsSize - 1);

    int currentQuery = 0, intervalsIndex = 0;
    for (int i = 0; i < queriesSize; i++) {
        currentQuery = queriesArray[i][0];

        while (intervalsIndex < intervalsSize && intervals[intervalsIndex][0] <= currentQuery) {
            insertToMinHeap(intervals[intervalsIndex][1] - intervals[intervalsIndex][0] + 1,
                            intervals[intervalsIndex][0],
                            intervals[intervalsIndex][1]);

            intervalsIndex++;
        }

        while (heapIndex > 0 && minHeap[0][2] < currentQuery) {
            removeMinHeapTop();
        }
        if (heapIndex > 0) {
            result[queriesArray[i][1]] = minHeap[0][0];
        } else {
            result[queriesArray[i][1]] = -1;
        }
    }

    return result;
}






int compareItem(bool isXSort, int *item1, int *item2) {
    if (isXSort) {
        if (item1[0] > item2[0]) {
            return 1;
        } else if (item1[0] < item2[0]) {
            return -1;
        } else {
            if (item1[1] > item2[1]) {
                return 1;
            } else if (item1[1] < item2[1]) {
                return -1;
            } else {
                return 0;
            }
        }
    } else {
        if (item1[1] > item2[1]) {
            return 1;
        } else if (item1[1] < item2[1]) {
            return -1;
        } else {
            if (item1[0] > item2[0]) {
                return 1;
            } else if (item1[0] < item2[0]) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

void quickSort(int** obstacles, int start, int end, bool isXSort) {
    if (start < end) {
        int randomIndex = rand() % (end - start + 1) + start;
        if (start != randomIndex) {
            int *tmp = obstacles[randomIndex];
            obstacles[randomIndex] = obstacles[start];
            obstacles[start] = tmp;
        }

        int *target = obstacles[start], i = start, j = end;
        while (i < j) {
            while (i < j && compareItem(isXSort, obstacles[j], target) > 0) {
                j--;
            }
            if (i < j) {
                obstacles[i++] = obstacles[j];
            }
            while (i < j && compareItem(isXSort, obstacles[j], target) <= 0) {
                i++;
            }
            if (i < j) {
                obstacles[j--] = obstacles[i];
            }
        }

        obstacles[i] = target;

        quickSort(obstacles, start, i-1, isXSort);
        quickSort(obstacles, i + 1, end, isXSort);
    }
}

int *halfCheckLatestPoint(int **obstacles, int obstaclesSize, int *item, int endP, bool isHorizontal, bool isUpDirection) {
    if (obstacles == NULL || obstaclesSize == 0) {
        return NULL;
    }

    int left = 0, right = obstaclesSize - 1, mid = 0, lastRight = isUpDirection ? obstaclesSize : -1;
    while (left <= right) {
        mid = (left + right) / 2;

        if (isUpDirection) {
            if (compareItem(!isHorizontal, obstacles[mid], item) >= 0) {
                lastRight = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (compareItem(!isHorizontal, obstacles[mid], item) <= 0) {
                lastRight = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    if (isUpDirection) {
        if (lastRight == obstaclesSize) {
            return NULL;
        } else {
            int *result = (int *)malloc(sizeof(int) * 2);
            result[0] = obstacles[lastRight][0];
            result[1] = obstacles[lastRight][1];
            if (isHorizontal) {
                result[0] -= 1;
                if (result[0] >= endP) {
                    result[0] = endP;
                }
            } else {
                result[1] -= 1;
                if (result[1] >= endP) {
                    result[1] = endP;
                }
            }

            return result;
        }
    } else {
        if (lastRight == -1) {
            return NULL;
        } else {
            int *result = (int *)malloc(sizeof(int) * 2);
            result[0] = obstacles[lastRight][0];
            result[1] = obstacles[lastRight][1];
            if (isHorizontal) {
                result[0] += 1;
                if (result[0] <= endP) {
                    result[0] = endP;
                }
            } else {
                result[1] += 1;
                if (result[1] <= endP) {
                    result[1] = endP;
                }
            }

            return result;
        }
    }
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int directIndex = 0;
    int currentPos[2] = {0, 0};
    int **sortedYObstacles = NULL;
    if (obstaclesSize > 0) {
        sortedYObstacles = (int **)malloc(sizeof(int *) * obstaclesSize);
        for (int i = 0; i < obstaclesSize; i++) {
            sortedYObstacles[i] = (int *)malloc(sizeof(int) * (obstaclesColSize[i]));
            for (int j = 0; j < obstaclesColSize[i]; j++) {
                sortedYObstacles[i][j] = obstacles[i][j];
            }
        }
    }
    quickSort(obstacles, 0, obstaclesSize - 1, true);
    quickSort(sortedYObstacles, 0, obstaclesSize - 1, false);

    int command = 0, startP = 0, endP = 0, len = 0, maxLen = 0;
    for (int i = 0; i < commandsSize; i++) {
        command = commands[i];

        if (command == -2) {
            directIndex = (directIndex + 3) % 4;
        } else if (command == -1) {
            directIndex = (directIndex + 1) % 4;
        } else {
            if (directIndex == 0 || directIndex == 2) {
                // Y方向
                startP = currentPos[1];
                endP = currentPos[1] + direct[directIndex][1] * command;

                int *nearestPoint = halfCheckLatestPoint(obstacles, obstaclesSize, currentPos, endP, false, directIndex == 0);
                if ((nearestPoint == NULL) || (nearestPoint[0] != currentPos[0])) {
                    currentPos[1] = endP;
                } else {
                    currentPos[1] = nearestPoint[1];
                }
                if (nearestPoint) {
                    free(nearestPoint);
                }
            } else {
                // X方向
                startP = currentPos[0];
                endP = currentPos[0] + direct[directIndex][0] * command;

                int *nearestPoint = halfCheckLatestPoint(sortedYObstacles, obstaclesSize, currentPos, endP, true, directIndex == 1);
                if ((nearestPoint == NULL) || (nearestPoint[1] != currentPos[1])) {
                    currentPos[0] = endP;
                } else {
                    currentPos[0] = nearestPoint[0];
                }
                if (nearestPoint) {
                    free(nearestPoint);
                }
            }

            len = currentPos[0] * currentPos[0] + currentPos[1] * currentPos[1];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    free(sortedYObstacles);

    return maxLen;
}






bool checkCanBeNeighbour(char *word1, char *word2) {
    if (word1 == NULL || word2 == NULL || strlen(word1) == 0 || strlen(word2) == 0) {
        return false;
    }

    int w1Len = strlen(word1), w2Len = strlen(word2);
    if (w1Len != w2Len) {
        return false;
    }

    int notSameCount = 0;
    for (int i = 0; i < w1Len; i++) {
        if (word1[i] != word2[i]) {
            notSameCount += 1;
            if (notSameCount > 1) {
                return false;
            }
        }
    }

    return notSameCount == 1;
}

void dfsRecursiveA(int *tmp, int tmpSize, char *beginWord, char *endWord, int wLen, char ** wordList, int wordListSize, bool *visited, bool **canBeNeighbour,
                  int *maxResultSize, char ****result, int** returnColumnSizes, int* returnSize, int *minLen) {
    if (tmpSize >= *minLen) {
        return;
    }

    char *curWord = NULL;
    for (int i = 0; i < wordListSize; i++) {
        if (visited[i] == false) {
                if (canBeNeighbour[tmp[tmpSize - 1]][i]) {
                    visited[i] = true;
                    tmp[tmpSize] = i;

                    if (strcmp(wordList[i], endWord) == 0) {
                        if (tmpSize + 1 == *minLen) {
                            char **subResult = (char **)malloc(sizeof(char *) * (tmpSize + 1));
                            for (int j = 0; j < tmpSize + 1; j++) {
                                subResult[j] = (char *)malloc(sizeof(char) * (wLen + 1));
                                if (tmp[j] == wordListSize) {
                                    strcpy(subResult[j], beginWord);
                                } else {
                                    strcpy(subResult[j], wordList[tmp[j]]);
                                }
                            }

                            if (*returnSize >= *maxResultSize) {
                                (*maxResultSize) += 1;
                                (*result) = (char ***)realloc(*result, sizeof(char **) * (*maxResultSize));
                                (*returnColumnSizes) = (int *)realloc(*returnColumnSizes, sizeof(int) * (*maxResultSize));
                            }

                            (*result)[*returnSize] = subResult;
                            (*returnColumnSizes)[*returnSize] = *minLen;
                            (*returnSize) += 1;

                            visited[i] = false;

                            return;
                        } else {
                            // *minLen = tmpSize + 1;

                            // *maxResultSize = 1;
                            // (*result) = (char ***)realloc(*result, sizeof(char **) * (*maxResultSize));
                            // (*returnColumnSizes) = (int *)realloc(*returnColumnSizes, sizeof(int) * (*maxResultSize));

                            // if ((*result)[0] != NULL) {
                            //     free((*result)[0]);
                            // }

                            // (*result)[0] = subResult;
                            // (*returnColumnSizes)[0] = *minLen;
                            // *returnSize = 1;

                            visited[i] = false;

                            return;
                        }
                    } else {
                        dfsRecursiveA(tmp, tmpSize + 1, beginWord, endWord, wLen, wordList, wordListSize, visited, canBeNeighbour,
                                    maxResultSize, result, returnColumnSizes, returnSize, minLen);
                    }

                    visited[i] = false;
                }
        }
    }
}

char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes) {
//int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize) {
    if (beginWord == NULL || endWord == NULL || strlen(beginWord) == 0 || strlen(endWord) == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int bLen = strlen(beginWord), eLen = strlen(endWord);
    if (bLen != eLen) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    bool containEndWord = false;
    int endIndex = 0;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            containEndWord = true;
            endIndex = i;
            break;
        }
    }

    if (!containEndWord) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    } else if (checkCanBeNeighbour(beginWord, endWord)) {
        *returnSize = 1;
        *returnColumnSizes = (int *)malloc(sizeof(int) * 1);
        char ***result = (char ***)malloc(sizeof(char **) * 1);
        (*returnColumnSizes)[0] = 2;
        result[0] = (char **)malloc(sizeof(char *) * 2);
        result[0][0] = (char *)malloc(sizeof(char) * (bLen + 1));
        result[0][1] = (char *)malloc(sizeof(char) * (bLen + 1));
        strcpy(result[0][0], beginWord);
        strcpy(result[0][1], endWord);
        return result;
    }

    bool visited[wordListSize];
    memset(visited, 0, sizeof(visited));

    bool **canBeNeighbour = (bool **)malloc(sizeof(bool *) * (wordListSize + 1));
    
    for (int i = 0; i < wordListSize + 1; i++) {
        canBeNeighbour[i] = (bool *)malloc(sizeof(bool) * (wordListSize + 1));
        memset(canBeNeighbour[i], 0, sizeof(bool) * (wordListSize + 1));
    }

    char *left, *right;
    bool r;
    for (int i = 0; i < wordListSize + 1; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == wordListSize) {
                left = beginWord;
            } else {
                left = wordList[i];
            }
            if (j == wordListSize) {
                right = beginWord;
            } else {
                right = wordList[j];
            }

            r = checkCanBeNeighbour(left, right);
            canBeNeighbour[i][j] = r;
            canBeNeighbour[j][i] = r;
        }
    }

    int minLen = wordListSize + 2;

    int currentLevel = 1;
    int queue[wordListSize * 2 + 1], p = -1;
    queue[0] = wordListSize;
    queue[1] = -1;
    int front = 0, tail = 2;
    while (front < tail) {
        p = queue[front++];

        if (p == -1) {
            if (front == tail) {
                break;
            } else {
                queue[tail++] = -1;
                currentLevel += 1;
            }
        } else {
            if (p == endIndex) {
                minLen = currentLevel;
                break;
            }

            for (int i = 0; i < wordListSize; i++) {
                if (visited[i] == false && canBeNeighbour[i][p]) {
                    visited[i] = true;
                    queue[tail++] = i;
                }
            }
        }
    }

    int maxResultSize = 1;
    *returnColumnSizes = (int *)malloc(sizeof(int) * maxResultSize);
    char ***result = (char ***)malloc(sizeof(char **) * maxResultSize);
    *returnSize = 0;
    result[0] = NULL;
    
    int *temp = (int *)malloc(sizeof(int) * (wordListSize + 1));

    memset(visited, 0, sizeof(visited));
    temp[0] = wordListSize;
    dfsRecursiveA(temp, 1, beginWord, endWord, eLen, wordList, wordListSize, visited, canBeNeighbour,
                 &maxResultSize, &result, returnColumnSizes, returnSize, &minLen);

    free(temp);
    for (int i = 0; i < wordListSize + 1; i++) {
        free(canBeNeighbour[i]);
    }
    free(canBeNeighbour);
    if (minLen == wordListSize + 2) {
        for (int i = 0; i < maxResultSize; i++) {
            if (result[i] != NULL) {
                free(result[i]);
            }
        }
        if (result != NULL) {
            free(result);
        }
        free(*returnColumnSizes);

        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    } else {
        return result;
    }
}





int solveRecursive(char* s, int start, int end) {
    char ch;
    int index = start;
    int stack[101] = { 0 };
    int sTop = 0;
    int opStack[101] = { 0 }; // 1：+ 2: - 3: * 4: /
    int opsTop = 0;

    while (index <= end) {
        ch = s[index];

        if (ch == ' ') {
            index++;
        } else if (ch == '(') {
            int leftCount = 1, rIndex = index + 1;
            for (; rIndex <= end; rIndex++) {
                ch = s[rIndex];
                if (ch == '(') {
                    leftCount += 1;
                } else if (ch == ')') {
                    leftCount -= 1;
                    if (leftCount == 0) {
                        int result = solveRecursive(s, index + 1, rIndex - 1);

                        stack[sTop++] = result;

                        index = rIndex + 1;
                        break;
                    }
                }
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (opsTop > 0) {
                if ((opStack[opsTop - 1] == 3) || (opStack[opsTop - 1] == 4)) {
                    int num1 = stack[sTop - 2];
                    int num2 = stack[sTop - 1];
                    int result = num1 * num2;
                    if (opStack[opsTop - 1] == 4) {
                        result = num1 / num2;
                    }
                    stack[sTop - 2] = result;
                    sTop -= 1;
                    
                    opsTop -= 1;
                    
                    if (ch == '+') {
                        while (opsTop > 0) {
                            int num1 = stack[sTop - 2];
                            int num2 = stack[sTop - 1];
                            int result = (opStack[opsTop - 1] == 1) ? num1 + num2 : ((opStack[opsTop - 1] == 2) ? num1 - num2 :  ((opStack[opsTop - 1] == 3) ? num1 * num2 : num1 / num2));
                            stack[sTop - 2] = result;
                            sTop -= 1;
                            
                            opsTop -= 1;
                        }
                        opStack[opsTop++] = 1;
                    } else if (ch == '-') {
                        while (opsTop > 0) {
                            int num1 = stack[sTop - 2];
                            int num2 = stack[sTop - 1];
                            int result = (opStack[opsTop - 1] == 1) ? num1 + num2 : ((opStack[opsTop - 1] == 2) ? num1 - num2 :  ((opStack[opsTop - 1] == 3) ? num1 * num2 : num1 / num2));
                            stack[sTop - 2] = result;
                            sTop -= 1;
                            
                            opsTop -= 1;
                        }
                        opStack[opsTop++] = 2;
                    } else if (ch == '*') {
                        opStack[opsTop++] = 3;
                    } else {
                        opStack[opsTop++] = 4;
                    }
                } else if (ch == '+' || ch == '-') {
                    int num1 = stack[sTop - 2];
                    int num2 = stack[sTop - 1];
                    int result = (opStack[opsTop - 1] == 1) ? num1 + num2 : ((opStack[opsTop - 1] == 2) ? num1 - num2 : ((opStack[opsTop - 1] == 3) ? num1 * num2 : num1 / num2));
                    stack[sTop - 2] = result;
                    sTop -= 1;

                    if (ch == '+') {
                        opStack[opsTop-1] = 1;
                    } else if (ch == '-') {
                        opStack[opsTop-1] = 2;
                    } else if (ch == '*') {
                        opStack[opsTop-1] = 3;
                    } else {
                        opStack[opsTop-1] = 4;
                    }
                } else {
                    if (ch == '+') {
                        opStack[opsTop++] = 1;
                    } else if (ch == '-') {
                        opStack[opsTop++] = 2;
                    } else if (ch == '*') {
                        opStack[opsTop++] = 3;
                    } else {
                        opStack[opsTop++] = 4;
                    }
                }
            } else {
                if (ch == '+') {
                    opStack[opsTop++] = 1;
                } else if (ch == '-') {
                    opStack[opsTop++] = 2;
                } else if (ch == '*') {
                    opStack[opsTop++] = 3;
                } else {
                    opStack[opsTop++] = 4;
                }
            }

            index += 1;
        } else {
            int temp = ch - '0', rIndex = index + 1;
            for (; rIndex <= end; rIndex++) {
                ch = s[rIndex];
                if (ch >= '0' && ch <= '9') {
                    temp = temp * 10 + (ch - '0');
                } else {
                    break;
                }
            }

            stack[sTop++] = temp;

            index = rIndex;
        }
    }

    while (opsTop > 0) {
        int num1 = stack[sTop - 2];
        int num2 = stack[sTop - 1];
        int result = (opStack[opsTop - 1] == 1) ? num1 + num2 : ((opStack[opsTop - 1] == 2) ? num1 - num2 :  ((opStack[opsTop - 1] == 3) ? num1 * num2 : num1 / num2));
        stack[sTop - 2] = result;
        sTop -= 1;

        opsTop -= 1;
    }

    return stack[0];
}

int calculate(char * s) {
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }

    return solveRecursive(s, 0, strlen(s) - 1);
}





int main(int argc, const char * argv[]) {
    //int result = reverse(2147483647);
//    int result = reverse(32768);
//    int result = divide(12, 3);
//    printf("%d\n", result);
    
    
//    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
//    head->val = 1;
//    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    p2->val = 2;
//    struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    p3->val = 3;
//    struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    p4->val = -3;
//    struct ListNode *p5 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    p5->val = 4;
//    head->next = p2;
//    p2->next = p3;
//    p3->next = p4;
//    p4->next = p5;
//    p5->next = NULL;
//
//    struct ListNode* p = removeZeroSumSublists(head);
//
//    while (p != NULL) {
//        printf("%d\n", p->val);
//        p = p->next;
//    }
    
    
//    int *nums = (int *)malloc(sizeof(int) * 3);
//    nums[0] = 1;
//    nums[1] = 2;
//    nums[2] = 3;
//    nextPermutation(nums, 3);
    
//    char *board[9] = {".........","...3..5..",".........","...8.....","....116..",".........","......1..","........7",".......4."};
//    int boardColSize[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
//    bool result = isValidSudoku(board, 9, boardColSize);
//
//    printf("%d\n", result);
    
    
//    int** grid = (int **)malloc(sizeof(int *) * 5);
//    for (int i = 0; i < 5; i++) {
//        grid[i] = (int *)malloc(sizeof(int) * 8);
//    }
//    int copy[5][8] = {{1,1,1,1,1,1,1,0}, {1,0,0,0,0,1,1,0}, {1,0,1,0,1,1,1,0}, {1,0,0,0,0,1,0,1}, {1,1,1,1,1,1,1,0}};
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 8; j++) {
//            grid[i][j] = copy[i][j];
//        }
//    }
//
//    int gridSize = 5;
//    int gridColSize = 8;
    
    
    
//    int** grid = (int **)malloc(sizeof(int *) * 3);
//    for (int i = 0; i < 3; i++) {
//        grid[i] = (int *)malloc(sizeof(int) * 5);
//    }
//    int copy[3][5] = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 5; j++) {
//            grid[i][j] = copy[i][j];
//        }
//    }
//    int gridSize = 3;
//    int gridColSize = 5;
    
    
    
//    int** grid = (int **)malloc(sizeof(int *) * 7);
//    for (int i = 0; i < 7; i++) {
//        grid[i] = (int *)malloc(sizeof(int) * 7);
//    }
//    int copy[7][7] = {{1,1,1,1,1,1,1},{1,0,0,0,0,0,1},{1,0,1,1,1,0,1},{1,0,1,0,1,0,1},{1,0,1,1,1,0,1},{1,0,0,0,0,0,1},{1,1,1,1,1,1,1}};
//    for (int i = 0; i < 7; i++) {
//        for (int j = 0; j < 7; j++) {
//            grid[i][j] = copy[i][j];
//        }
//    }
//    int gridSize = 7;
//    int gridColSize = 7;
//
//
//
//
//    int lockIsland = closedIsland(grid, gridSize, &gridColSize);
//
//    printf("%d\n", lockIsland);
    
    
    
    
    
//    int** cost = (int **)malloc(sizeof(int *) * 2);
//    for (int i = 0; i < 2; i++) {
//        cost[i] = (int *)malloc(sizeof(int) * 2);
//    }
//    int copy[2][2] = {{15,96},{36,2}};
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 2; j++) {
//            cost[i][j] = copy[i][j];
//        }
//    }
//    int costSize = 2;
//    int costColSize = 2;
//
//    int minCost = connectTwoGroups(cost, costSize, &costColSize);
//
//    printf("%d\n", minCost);
    
    
    
    //[[1,3],[6,9]]
    //[2,5]
    
//    int **intervals = (int **)malloc(sizeof(int *) * 2);
//    intervals[0] = (int *)malloc(sizeof(int) * 2);
//    intervals[0][0] = 1;
//    intervals[0][1] = 3;
//    intervals[1] = (int *)malloc(sizeof(int) * 2);
//    intervals[1][0] = 6;
//    intervals[1][1] = 9;
//
//    int *intervalsColSize = (int *)malloc(sizeof(int) * 2);
//    intervalsColSize[0] = 2;
//    intervalsColSize[1] = 2;
//
//    int *newInterval = (int *)malloc(sizeof(int) * 2);
//    newInterval[0] = 2;
//    newInterval[1] = 5;
    
    
    //[[1,2],[3,5],[6,7],[8,10],[12,16]]
    //[4,8]
    
//    int **intervals = (int **)malloc(sizeof(int *) * 5);
//    intervals[0] = (int *)malloc(sizeof(int) * 2);
//    intervals[0][0] = 1;
//    intervals[0][1] = 2;
//    intervals[1] = (int *)malloc(sizeof(int) * 2);
//    intervals[1][0] = 3;
//    intervals[1][1] = 5;
//    intervals[2] = (int *)malloc(sizeof(int) * 2);
//    intervals[2][0] = 6;
//    intervals[2][1] = 7;
//    intervals[3] = (int *)malloc(sizeof(int) * 2);
//    intervals[3][0] = 8;
//    intervals[3][1] = 10;
//    intervals[4] = (int *)malloc(sizeof(int) * 2);
//    intervals[4][0] = 12;
//    intervals[4][1] = 16;
//
//    int *intervalsColSize = (int *)malloc(sizeof(int) * 5);
//    intervalsColSize[0] = 2;
//    intervalsColSize[1] = 2;
//    intervalsColSize[2] = 2;
//    intervalsColSize[3] = 2;
//    intervalsColSize[4] = 2;
//
//    int *newInterval = (int *)malloc(sizeof(int) * 2);
//    newInterval[0] = 4;
//    newInterval[1] = 8;
    
    
//    [[1,5]]
//    [2,3]
//    int **intervals = (int **)malloc(sizeof(int *) * 1);
//    intervals[0] = (int *)malloc(sizeof(int) * 2);
//    intervals[0][0] = 1;
//    intervals[0][1] = 5;
//
//    int *intervalsColSize = (int *)malloc(sizeof(int) * 1);
//    intervalsColSize[0] = 2;
//
//    int *newInterval = (int *)malloc(sizeof(int) * 2);
//    newInterval[0] = 2;
//    newInterval[1] = 3;
//
//    int resultSize = 0;
//    int *resultColumnSize = NULL;
//    int **result = insert(intervals, 1, intervalsColSize, newInterval, 2, &resultSize, &resultColumnSize);
//
//    for (int i = 0; i < resultSize; i++) {
//        printf("%d %d\n", result[i][0], result[i][1]);
//    }




//    int digits[4] = {4, 3, 2, 1};
//    int returnSize = 0;
//    int *result = plusOne(digits, 4, &returnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }

    

//    char *s = "ADOBECODEBANC";
//    char *t = "ABC";
//    char *result = minWindow(s, t);
//
//    printf("%s\n", result);
    
    
    
//    int returnSize = 0;
//    int *result = grayCode(2, &returnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d ", result[i]);
//    }
    
//    char *result = addStrings("1", "9");
//    int rLen = strlen(result);
//    for (int i = 0; i < rLen; i++) {
//        printf("%c", result[i]);
//    }
    
    
//    struct TreeNode *leftRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//    leftRoot->val = 9;
//    leftRoot->left = NULL;
//    leftRoot->right = NULL;
//
//    struct TreeNode *rightLeft = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//    rightLeft->val = 15;
//    rightLeft->left = NULL;
//    rightLeft->right = NULL;
//
//    struct TreeNode *rightRight = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//    rightRight->val = 7;
//    rightRight->left = NULL;
//    rightRight->right = NULL;
//
//    struct TreeNode *rightRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//    rightRoot->val = 20;
//    rightRoot->left = rightLeft;
//    rightRoot->right = rightRight;
//
//    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//    root->val = 3;
//    root->left = leftRoot;
//    root->right = rightRoot;
//
//
//    int returnSize = 0, *returnColumnSize = NULL;
//    int **result = levelOrderBottom(root, &returnSize, &returnColumnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("[");
//        for (int j = 0; j < returnColumnSize[i]; j++) {
//            printf("%d,", result[i][j]);
//        }
//        printf("]");
//    }
    
    
    
//    int **intervals = (int **)malloc(sizeof(int *) * 5);
//    for (int i = 0; i < 5; i++) {
//        intervals[i] = (int *)malloc(sizeof(int) * 2);
//    }
//    intervals[0][0] = 9;
//    intervals[0][1] = 9;
//    intervals[1][0] = 6;
//    intervals[1][1] = 7;
//    intervals[2][0] = 5;
//    intervals[2][1] = 6;
//    intervals[3][0] = 2;
//    intervals[3][1] = 5;
//    intervals[4][0] = 3;
//    intervals[4][1] = 3;
//
//    int *queries = (int *)malloc(sizeof(int) * 5);
//    queries[0] = 6;
//    queries[1] = 1;
//    queries[2] = 1;
//    queries[3] = 1;
//    queries[4] = 9;
//
//    int returnSize = 0;
//    int* result = minInterval(intervals, 5, NULL, queries, 5, &returnSize);
//    for (int i = 0; i < returnSize; i++) {
//        printf("%d,", result[i]);
//    }
    
    
    
    
    
//    int *commands = (int *)malloc(sizeof(int) * 5);
//    int **obstacles = (int **)malloc(sizeof(int *) * 10);
//    int *obstaclesColSize = (int *)malloc(sizeof(int) * 10);
//    commands[0] = -2;
//    commands[1] = -1;
//    commands[2] = 8;
//    commands[3] = 9;
//    commands[4] = 6;
//    for (int i = 0; i < 10; i++) {
//        obstacles[i] = (int *)malloc(sizeof(int) * 2);
//        obstaclesColSize[i] = 2;
//    }
//    obstacles[0][0] = -1;
//    obstacles[0][1] = 3;
//    obstacles[1][0] = 0;
//    obstacles[1][1] = 1;
//    obstacles[2][0] = -1;
//    obstacles[2][1] = 5;
//    obstacles[3][0] = -2;
//    obstacles[3][1] = -4;
//    obstacles[4][0] = 5;
//    obstacles[4][1] = 4;
//    obstacles[5][0] = -2;
//    obstacles[5][1] = -3;
//    obstacles[6][0] = 5;
//    obstacles[6][1] = -1;
//    obstacles[7][0] = 1;
//    obstacles[7][1] = -1;
//    obstacles[8][0] = 5;
//    obstacles[8][1] = 5;
//    obstacles[9][0] = 5;
//    obstacles[9][1] = 2;
//
//    int result = robotSim(commands, 5, obstacles, 10, obstaclesColSize);
//
//    printf("%d", result);
    
    
    
    
    char *beginWord = "hit";
    char *endWord = "cog";
//    char **wordList = (char **)malloc(sizeof(char *) * 6);
//    for (int i = 0; i < 6; i++) {
//        wordList[i] = (char *)malloc(sizeof(char) * 4);
//    }
//    strcpy(wordList[0], "hot");
//    strcpy(wordList[1], "dot");
//    strcpy(wordList[2], "dog");
//    strcpy(wordList[3], "lot");
//    strcpy(wordList[4], "log");
//    strcpy(wordList[5], "cog");
    
//    char **wordList = (char **)malloc(sizeof(char *) * 5);
//    for (int i = 0; i < 5; i++) {
//        wordList[i] = (char *)malloc(sizeof(char) * 4);
//    }
//    strcpy(wordList[0], "hot");
//    strcpy(wordList[1], "dot");
//    strcpy(wordList[2], "dog");
//    strcpy(wordList[3], "lot");
//    strcpy(wordList[4], "log");
//
//    int returnSize = 0;
//    int *returnColumnSizes = NULL;
//    char *** result = findLadders(beginWord, endWord, wordList, 5, &returnSize, &returnColumnSizes);
//    for (int i = 0; i < returnSize; i++) {
//        printf("[");
//        for (int j = 0; j < returnColumnSizes[i]; j++) {
//            printf("%s,", result[i][j]);
//        }
//        printf("]\n");
//    }
    
    
    char *s = "1*2-3/4+5*6-7*8+9/10";
    int result = calculate(s);
    printf("%d\n", result);
    
    
    return 0;
}




