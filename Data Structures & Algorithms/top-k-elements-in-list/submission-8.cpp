class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> occurNums;
        vector<int> res(k, 0);

        for(int i = 0; i < n; i++) {
            occurNums[nums[i]]++;
        }

        vector<pair<int, int>> temp(occurNums.begin(), occurNums.end());

        sort(temp.begin(), temp.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            }
        );

        for(int i = 0; i < res.size(); i++) {
            res[i] = temp[i].first;
        }

        return res;
    }
};
