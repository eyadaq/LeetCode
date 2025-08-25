#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col[9] = {0};
        int box[9] = {0};
        int row[9] = {0};

        for (int i = 0; i < 9 ; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int mask =  1 << (board[i][j] - '1');
                int k = ((i / 3) * 3 ) + (j / 3);
                if ( col[j] & mask || row[i] & mask || box[k] & mask)
                    return false;
                col[j] |= mask;
                row[i] |= mask;
                box[k] |= mask;
            }
        }
        return true;
    }
};
