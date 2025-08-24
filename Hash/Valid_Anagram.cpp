#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
// if this question only requires english letters we can use a fixed array for the general solution its better to use the unordered_map -> hashTable
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        unordered_map<char, int> hashTable;

        for (char c : s)
        {
            hashTable[c]++;
        }

        for (char c : t)
        {
            if (hashTable.find(c) == hashTable.end() || (hashTable[c] == 0 ))
                return false;
                
            hashTable[c]--;
        }

        return true;
    }
};