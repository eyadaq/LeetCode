#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> hashTable;
        vector<vector<string>> ans;

        for (auto& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            hashTable[key].push_back(s);
        }

        for (auto& h : hashTable)
        {   
            ans.push_back(h.second);
        }
        return ans;
    }
};