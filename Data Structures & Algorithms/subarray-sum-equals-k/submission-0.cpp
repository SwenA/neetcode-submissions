class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        int x = 0;

        for(int i = 0; i < n; i++){
            x = 0;
            for(int j = i; j < n; j++){
                if(nums[j] + x - k == 0) res++;
                x += nums[j];
            }
        }

        return res;
        
    }
};