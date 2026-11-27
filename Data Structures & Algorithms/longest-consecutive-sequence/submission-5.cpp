class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;
        int n = nums.size();
        unordered_map<int, int> sequences;
        int res = 0;
        int curr;

        for(int i = 0; i < n; i++) {
            sequences[nums[i]] = 1;
        }

        for(auto& [key, value] : sequences) {
            if(sequences.contains(key-1)) continue;
            while(sequences.contains(key + value)) {
                value++;
            }
            res = max(res,value);
        }

        return res;
    }
};
