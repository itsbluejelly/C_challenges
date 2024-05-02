#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * findMaxk - Function finds the largext positive integer.
 * @nums: Array of integers
 * @numsSize: The size of the array
 * Return: k, the largest positive integer.
*/
int findMaxK(int* nums, int numsSize)
{
    int k = -1;
    int i, j;

    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == abs(nums[j]) && nums[i] != nums[j])
            {
                if (nums[i] > k)
                {
                    k = nums[i];
                }
            }
            else if (abs(nums[i]) == nums[j] && nums[i] != nums[j])
            {
                if (nums[j] > k)
                {
                    k = nums[j];
                }
            }
        }
    }
    return (k);
}

int main(void)
{
    int res;
    int n = 8;
    int arr[8] = {-25,25,-27,45,31,46,46,21};

    res = findMaxK(arr, n);
    printf("Max K: %d\n", res);

    return (0);
}