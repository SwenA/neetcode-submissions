class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        vector<string> sortedStrs = strs;
        unordered_map<string, vector<string>> anagrams;

        for(int i = 0; i < n; i++) {
            std::sort(sortedStrs[i].begin(), sortedStrs[i].end());
            anagrams[sortedStrs[i]].push_back(strs[i]);
        }

        for(const auto& [key, value] : anagrams) {
            res.push_back(value);
        }

        return res;
    }
};
