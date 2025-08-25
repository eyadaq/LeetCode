#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        
        for (int i = 0; i < strs.size(); i++)
        {
            ans += strs[i] + "💀";
        }
        return ans;
    }

    vector<string> decode(string s) {
       vector<string> ans;
        
       int start = 0;
       int pos = s.find("💀", start);

       while (start != s.size())
       {
            ans.push_back(s.substr(start, pos - start));
            start = pos + 4;
            pos = s.find("💀", start);
       }
       return ans;
    }
};
