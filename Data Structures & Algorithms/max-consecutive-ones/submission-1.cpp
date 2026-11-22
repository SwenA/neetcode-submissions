class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int current = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                max = (current > max) ? current : max;
                current = 0;
                continue;
            }
            current++;
        }

        return (current > max) ? current : max;
    }
};