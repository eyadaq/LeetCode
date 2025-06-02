#include <stdlib.h>

//Time Comp = O²
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int i;
	int j;
	int *ans;

	ans = malloc(2 * sizeof(int));
	if (!ans)
		return (NULL);
	i = 0;
	while (i < numsSize)
	{
		j = i + 1;
		while (j < numsSize)
		{
			if (nums[i] + nums[j] == target)
			{
				ans[0] = i;
				ans[1] = j;
				*returnSize = 2;
				return (ans);
			}
			j++;
		}
		i++;
	}
	free(ans);
	*returnSize = 0;
	return (NULL);
}
