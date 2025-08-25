#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        vector<int> ans;

        for (auto& a : nums) {
            hashTable[a]++;
        }

        while (k > 0 && !hashTable.empty()) {
            auto max_it = max_element(hashTable.begin(), hashTable.end(),
                                      [](const auto& a, const auto& b) {
                                          return a.second < b.second;
                                      });

            ans.push_back(max_it->first);
            hashTable.erase(max_it);
            k--;
        }

        return ans;
    }
};
