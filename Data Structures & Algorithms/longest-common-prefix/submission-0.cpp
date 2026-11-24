class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string prefix = "";
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j][i] != strs[j-1][i]) return prefix;            
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};