#include <stdio.h>

int storeWater(int* bucket, int bucketSize, int* vat, int vatSize){
    int currentAddOpCount = 0, minOpCount = 1000001;
    for (int i = 0; i < minOpCount; i++) {
        currentAddOpCount = i + 1;

        for (int j = 0; j < bucketSize; j++) {
            int addToSize = (vat[j] + i) / (i + 1);
            if (bucket[j] < addToSize) {
                currentAddOpCount += (addToSize - bucket[j]);
            }
        }

        if (currentAddOpCount < minOpCount) {
            minOpCount = currentAddOpCount;
        }
    }

    return minOpCount;
}

int main() {
    int bucket[2] = {1,3}, vat[2] = {6,8};
    int result = storeWater(bucket, 2, vat, 2);
    printf("%d\n", result);
    return 0;
}
