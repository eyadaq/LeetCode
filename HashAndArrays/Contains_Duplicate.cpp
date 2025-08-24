#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public :
    bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> freq;

    for (int n : nums) {
        // if the item is not available in the set it will return a special value equals the value returned from .end
        if (freq.find(n) != freq.end()) {
            return true;
        }
        freq.insert(n);
    }
    return false;
}
};