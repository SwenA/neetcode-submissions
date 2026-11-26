class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> occurNums;
        vector<int> res(k, 0);

        for(int i = 0; i < n; i++) {
            occurNums[nums[i]]++;
        }

        for(int i = 0; i < res.size(); i++) {
            auto max = max_element(occurNums.begin(), occurNums.end(),
                [](const auto& a, const auto& b) {
                    return a.second < b.second;
                }
            );
            res[i] = max->first;
            occurNums.erase(max->first);
        }

        return res;
    }
};
