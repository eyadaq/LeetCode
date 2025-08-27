
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, temp = 0, x = 0, i = height.size() - 1;

        while (x < i + 1)
        {
            
            if (height[x] >= height[i])
            {
                temp = (i - x) *  height[i];
                i--;
            }
            else {
                temp = (i - x) *  height[x];
                x++;
            }
            max = (temp > max) ? temp : max;
        }
        return max;
    }
};