#include <stdio.h>
#include <stdbool.h>
bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    if (containsDuplicate(nums, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
