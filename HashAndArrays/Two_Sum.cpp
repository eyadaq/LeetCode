#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            // look for the complement if its prev added then we got the answer
            if (hash.find(comp) != hash.end())
            {
                ans.push_back(i);
                ans.push_back(hash[comp]);
                return ans;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};