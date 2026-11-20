class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++) {
            if(!map.contains(target-nums[i])) map[target - nums[i]] = i;
            if(map.contains(nums[i])) {
                if (map[nums[i]] != i ) return {map[nums[i]], i};
            }
        }
        return {0,0};
    }
};
