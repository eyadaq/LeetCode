
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int indexOfZero = 0;
        int res = 0;
        for (int num : nums)
        {
            if (num == 0)
            {
                indexOfZero++;
            }
            else {
                if (res == 0)
                    res = num;
                else 
                    res *= num;
            }
        }
        int max = 0;

        while (max < nums.size())
        {
            if (indexOfZero)
            {
                if (nums[max] == 0 && indexOfZero == 1)
                    result.push_back(res);
                else
                    result.push_back(0);
            }
            else {
                result.push_back(res / nums[max]);
            }
            max++;
        }
        return result;
    }
};
