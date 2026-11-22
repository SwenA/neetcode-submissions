static const int fastIO = [] {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int zero = 0;
        vector<int> res(nums.size(),0);

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zero++;
                continue;
            }
            prefix *= nums[i];
        }

        if(zero >= 2) return res;
        for(int i = 0; i < n; i++) {
            if(zero == 0) nums[i] = prefix / nums[i];
            if(nums[i] == 0) {
                nums[i] = prefix;
                continue;
                }
            if(zero > 0 && nums[i] != 0) nums[i] = 0;

        }

        return nums;


    }
};
