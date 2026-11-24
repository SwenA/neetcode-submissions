class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, curSum = 0, n = nums.size();
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        for(int i = 0; i < n; i++) {
            curSum += nums[i];
            int diff = curSum - k;
            res += prefixSum[diff];
            prefixSum[curSum]++;

        } 
        
        return res;
        
    }
};