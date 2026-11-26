class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> checkMapR[9];
        unordered_set<char> checkMapC[9];
        unordered_set<char> checkMapS[9];


        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                char num = board[i][j];

                if(num == '.') continue;

                int squareIdx = (i / 3) * 3 + (j / 3);

                if(checkMapR[i].contains(num) || 
                   checkMapC[j].contains(num) || 
                   checkMapS[squareIdx].contains(num)) return false;

                checkMapR[i].insert(num);
                checkMapC[j].insert(num);
                checkMapS[squareIdx].insert(num);
                
            }
        }

        return true;

    }
};
