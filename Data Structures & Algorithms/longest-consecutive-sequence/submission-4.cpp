class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> sequences;
        int res = 0;
        int curr;

        for(int i = 0; i < n; i++) {
            sequences[nums[i]] = 1;
        }

        for(auto& [key, value] : sequences) {
            while(sequences.contains(key + value)) {
                curr = key + value;
                if(sequences[key + value] > 1) { 
                    value += sequences[key + value];
                    continue; 
                    } 
                value++;
                sequences.erase(curr);
            }
            res = max(res,value);
        }

        return res;
    }
};
