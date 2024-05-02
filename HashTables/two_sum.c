#include <stdio.h>
#include <stdlib.h>
/**
 * twoSum - return the position of values that attain sum of target value.
 * @nums: The array of numbers.
 * @numsSize: The Size of array.
 * @target: The target Value.
 * @returnSize: Size of the returned value.
 * Return: Array of positions
*/
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, complement, complementIndex;
    int *res;
    int hashSize = 100;
    int *hashTable;

    res = (int *)malloc(2 * sizeof(int));
    if (!res)
    {
        *returnSize = 0;
        fprintf(stderr, "Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    hashTable = (int*)calloc(hashSize, sizeof(int));
    if (!hashTable)
    {
        free(res);
        *returnSize = 0;
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < numsSize; i++)
    {
        complement = target - nums[i];
        complementIndex = hashTable[complement % hashSize];
        if (complementIndex != 0)
        {
            res[0] = complementIndex - 1;
            res[1] = i;
            *returnSize = 2;
            free(hashTable);
            return (res);
        }
        hashTable[nums[i] % hashSize] = i + 1;
    }

    /*For no valid solution found.*/
    free(hashTable);
    *returnSize = 0;
    return NULL;
}

/*Main Test Function*/
int main(void)
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result)
    {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    }
    else
    {
        printf("No two sum solution found.\n");
    }

    return (0);
}