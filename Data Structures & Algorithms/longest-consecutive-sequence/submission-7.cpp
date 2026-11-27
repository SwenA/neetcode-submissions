class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for(auto& num : numSet) {
            if(numSet.find(num-1) != numSet.end()) continue;
            int currLength = 1;
            while(numSet.find(num + currLength) != numSet.end()) {
                currLength++;
            }
            res = max(res,currLength);
        }

        return res;
    }
};
